/* Multifit.h
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
#include "Jacobian.h"
#include <gsl/gsl_multifit_nlin.h>
#include <gsl/gsl_vector.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>����`�ŏ����@�\���o�[�N���X</summary>
public ref class Multifit
{
private:
	~Multifit();
	gsl_multifit_fdfsolver *fSolver;

internal:
	array<double>^ inputs;
	array<double>^ outputs;
	array<array<double>^>^ jacobian;
	GSLFunctions::DArrayToDArray ^eFnc;
	gsl_vector *xVector;
	gsl_vector *gVector;

public:
	///<summary>����`�ŏ����@�̎��</summary>
	enum class SolverType {
		///<summary>�X�P�[�����O�t��Levenberg-Marquardt�@</summary>
		LevenbergMarquardtWithScaling,
		///<summary>Levenberg-Marquardt�@</summary>
		LevenbergMarquardt,
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="sType">����`�ŏ����@�̎��</param>
	///<param name="dataNumber">�f�[�^�_��</param>
	///<param name="parameterNumber">�p�����[�^��</param>
	Multifit(SolverType sType, size_t dataNumber, size_t parameterNumber);

	///<summary>�����v�Z�ɂ���ăp�����[�^���œK������</summary>
	///<param name="initialX">�T���J�n�_</param>
	///<param name="epsabs">��Ό덷</param>
	///<param name="epsrel">���Ό덷</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="iterNum">������</param>
	///<returns>�G���[�R�[�h</returns>
	///<remarks>�X�e�b�v���ƒT���_���A��Ό덷����ё��Ό덷���g���Ĕ�r���A�����𔻒肷��</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, double epsrel, int maxIteration, [Out] int %iterNum);

	///<summary>�����v�Z�ɂ���ăp�����[�^���œK������</summary>
	///<param name="initialX">�T���J�n�_</param>
	///<param name="epsabs">��Ό덷</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="iterNum">������</param>
	///<returns>�G���[�R�[�h</returns>
	///<remarks>�X�e�b�v���ƒT���_���A��Ό덷����ё��Ό덷���g���Ĕ�r���A�����𔻒肷��</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, int maxIteration, [Out] int %iterNum);

	///<summary>�c�����擾����</summary>
	///<returns>�c��</returns>
	double GetResidualError();
};

int __cdecl multifitErrorFunction (const gsl_vector * x, void *params, gsl_vector * f)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Multifit^ mFit = (Multifit^)gch.Target;

	array<double>^ inputs = mFit->inputs;
	array<double>^ outputs= mFit->outputs;
	int dimension = inputs->Length;
	int paramNumber = outputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}

	mFit->eFnc(inputs, outputs);

	for(int i=0;i<paramNumber;i++){
		gsl_vector_set(f, i, outputs[i]);
	}

	return GSL_SUCCESS;
}

int __cdecl multifitErrorFunctionFD (const gsl_vector * x, void *params, gsl_matrix * jac)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Multifit^ mFit = (Multifit^)gch.Target;

	array<double>^ inputs = mFit->inputs;
	array<double>^ outputs= mFit->outputs;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}
	Jacobian::Calculate(mFit->eFnc, inputs, mFit->jacobian);

	int dataNumber = mFit->jacobian[0]->Length;
	for(int i=0;i<dataNumber;i++){
		for(int j=0;j<dimension;j++){
			gsl_matrix_set(jac, i, j, mFit->jacobian[j][i]);
		}
	}

	return GSL_SUCCESS;
}

int __cdecl multifitErrorFunctionFDF (const gsl_vector * x, void *params, gsl_vector * f, gsl_matrix * jac)
{
	multifitErrorFunction(x, params, f);
	multifitErrorFunctionFD(x, params, jac);
	return GSL_SUCCESS;
}


}