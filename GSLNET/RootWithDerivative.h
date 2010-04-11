/* RootWithDerivative.h
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

#include <gsl/gsl_roots.h>
#include <gsl/gsl_deriv.h>
#include "GSLFunctions.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class RootWithDerivative
{
public:

	///<summary>��@�̎��</summary>
	enum class SolverType {
		///<summary>�j���[�g���@</summary>
		Newton,
		///<summary>�����@</summary>
		Secant,
		///<summary>�X�e�t�F���\���̕��@</summary>
		Steffenson,
	};

	///<summary>��������</summary>
	enum class Convergence {
		///<summary>�c���̎����F|f| �� epsabs</summary>
		Residual,
		///<summary>�ω��ʂ̎����F|x1-x0| �� epsabs + epsrel |x1|</summary>
		Delta,
	};

	///<summary>����������ݒ�E�擾����</summary>
	Convergence ConvergenceType;

	///<summary>���Ό덷��ݒ�E�擾����</summary>
	double RelativeError;

	///<summary>��Ό덷��ݒ�E�擾����</summary>
	double AbsoluteError;

	///<summary>�����l�a�Z�p������ݒ�E�擾����</summary>
	double DeltaH;

	///<summary>�����v�Z�񐔂��擾����</summary>
	int Iteration(){
		return this->iteration;
	}

	///<summary>�R���X�g���N�^</summary>
	///<param name="sType">��@�̎��</param>
	RootWithDerivative(SolverType sType);

	///<summary>�����v�Z�ɂ����f(x)=0�ƂȂ�x�����߂�</summary>
	///<param name="eFnc">�֐�f(x)</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="xValue">�����l</param>
	///<returns>�G���[�R�[�h</returns>
	ErrorNumber Solve(GSLFunctions::DToD ^ eFnc, int maxIteration, double %xValue);

	///<summary>�����v�Z�ɂ����f(x)=0�ƂȂ�x�����߂�</summary>
	///<param name="eFnc">�֐�f(x)</param>
	///<param name="eFncDF">�����l�v�Z�֐�df(x)</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="xValue">�����l</param>
	///<returns>�G���[�R�[�h</returns>
	ErrorNumber RootWithDerivative::Solve(GSLFunctions::DToD ^eFnc, GSLFunctions::DToD ^ eFncDF, int maxIteration, double %xValue);

private:
	ErrorNumber solve(int maxIteration, double %xValue);
	gsl_root_fdfsolver * solver;
	~RootWithDerivative();
	int iteration;

internal:
	bool hasFDFunction;
	GSLFunctions::DToD ^ eFnc;
	GSLFunctions::DToD ^ eFncDF;

};

double __cdecl rootWithDerivativeFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	RootWithDerivative^ root = (RootWithDerivative^)gch.Target;
	return root->eFnc(x);
}

double __cdecl rootWithDerivativeFunctionDF (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	RootWithDerivative^ root = (RootWithDerivative^)gch.Target;

	if(root->hasFDFunction){
		return root->eFncDF(x);
	}
	else{
		return (root->eFnc(x + root->DeltaH) - root->eFnc(x)) / root->DeltaH;
	}
}

void __cdecl rootWithDerivativeFunctionFDF (double x, void * params, double *y, double *dy)
{
	*y = rootWithDerivativeFunction(x, params);
	*dy = rootWithDerivativeFunctionDF(x, params);
}

}