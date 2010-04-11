/* MultiRoot.h
 * 
 * Copyright (C) 2008 E.Togashi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#pragma once

#include "ErrorNumber.h"
#include "GSLFunctions.h"
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_vector.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET {

///<summary>�������֐������N���X�i�����l�͗L�������ߎ�����j</summary>
public ref class MultiRoot
{

public:
	///<summary>�������֐������@�̎��</summary>
	enum class SolverType {
		///<summary>�X�P�[�����O�t�̃p�E�G���̏C���g�ݍ��킹�@</summary>
		ScalingHybrid,
		///<summary>�p�E�G���̏C���g�ݍ��킹�@</summary>
		Hybrid,
		///<summary>�j���[�g���E���v�\���@</summary>
		Newton,
		///<summary>�u���C�f���@</summary>
		Broyden
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="type">�������֐������@�̎��</param>
	///<param name="n">������</param>
	MultiRoot(SolverType type, size_t n);

	///<summary>�����_�̉���Ԃ�</summary>
	array<double>^ GetRoots();

	///<summary>�����_�̊֐��lf(x)��Ԃ�</summary>
	array<double>^ GetOutputs();

	///<summary>���O�Ɏ�����X�e�b�v��dX��Ԃ�</summary>
	array<double>^ GetDx();

	///<summary>�����v�Z�ɂ���č������߂�</summary>
	///<param name="initialX">�T���J�n�_</param>
	///<param name="epsabs">��Ό덷</param>
	///<param name="epsrel">���Ό덷</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="iterNum">������</param>
	///<remarks>�X�e�b�v���ƒT���_���A��Ό덷����ё��Ό덷���g���Ĕ�r���A�����𔻒肷��</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, double epsrel, int maxIteration, [Out] int %iterNum);

	///<summary>�����v�Z�ɂ���č������߂�</summary>
	///<param name="initialX">�T���J�n�_</param>
	///<param name="epsabs">��Ό덷</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="iterNum">������</param>
	///<remarks>�֐��o��f(x)�Ɛ�Ό덷�ɂ���Ď����𔻒肷��</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, int maxIteration, [Out] int %iterNum);

private:
	gsl_multiroot_fsolver *fSolver;
	array<double>^ dX;
	~MultiRoot();

internal:
	array<double>^ inputs;
	array<double>^ outputs;
	GSLFunctions::DArrayToDArray ^eFnc;

};

int __cdecl multiRootErrorFunction (const gsl_vector * x, void *params, gsl_vector * f)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	MultiRoot^ mRoot = (MultiRoot^)gch.Target;

	array<double>^ inputs = mRoot->inputs;
	array<double>^ outputs= mRoot->outputs;
	int dimension = inputs->Length;
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}
	int eNum = (int)mRoot->eFnc(inputs, outputs);
	for(int i=0;i<dimension;i++){
		gsl_vector_set(f, i, outputs[i]);
	}
	return GSL_SUCCESS;
}

}