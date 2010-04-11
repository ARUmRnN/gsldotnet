/* Root.h
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
#include "GSLFunctions.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class Root
{
public:

	///<summary>��@�̎��</summary>
	enum class SolverType {
		///<summary>�񕪖@</summary>
		Bisection,
		///<summary>���s�_�@</summary>
		FalsePosition,
		///<summary>�u�����g�@</summary>
		BrentDekker,
	};

	///<summary>��������</summary>
	enum class Convergence {
		///<summary>�c���̎����F|f| �� epsabs</summary>
		Residual,
		///<summary>��Ԃ̎����F|a-b| �� epsabs + epsrel min(|a|,|b|)</summary>
		Interval,
		///<summary>�ω��ʂ̎����F|x1-x0| �� epsabs + epsrel |x1|</summary>
		Delta,
	};

	///<summary>����������ݒ�E�擾����</summary>
	Convergence ConvergenceType;

	///<summary>���Ό덷��ݒ�E�擾����</summary>
	double RelativeError;

	///<summary>��Ό덷��ݒ�E�擾����</summary>
	double AbsoluteError;

	///<summary>�R���X�g���N�^</summary>
	///<param name="sType">��@�̎��</param>
	Root(SolverType sType);

	///<summary>�����v�Z�ɂ����f(x)=0�ƂȂ�x�����߂�</summary>
	///<param name="eFnc">�֐�f(x)</param>
	///<param name="lowerX">�T���͈͉���</param>
	///<param name="upperX">�T���͈͏��</param>
	///<param name="maxIteration">�ő唽����</param>
	///<param name="xValue">��</param>
	///<returns>�G���[�R�[�h</returns>
	ErrorNumber Solve(GSLFunctions::DToD ^ eFnc, double lowerX, double upperX, int maxIteration, [Out] double %xValue);

	///<summary>�����v�Z�񐔂��擾����</summary>
	int Iteration(){
		return this->iteration;
	}

private:
	gsl_root_fsolver * solver;
	~Root();
	int iteration;

internal:
	GSLFunctions::DToD ^ eFnc;

};

double __cdecl rootsFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Root^ root = (Root^)gch.Target;
	return root->eFnc(x);
}

}