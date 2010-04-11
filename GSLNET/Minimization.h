/* Minimization.h
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
#include <gsl/gsl_min.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>�ꎟ���֐��œK���N���X</summary>
public ref class Minimization
{
public:
	///<summary>�ꎟ���֐��œK���@�̎��</summary>
	enum class SolverType {
		///<summary>�����T���@</summary>
		GoldenSection,
		///<summary>Brent�@</summary>
		Brent,
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="sType">�ꎟ���֐��œK���@�̎��</param>
	Minimization(SolverType sType);

	///<summary>�����v�Z�ɂ����f(x)���ŏ�������x�����߂�</summary>
	///<param name="minimizeFunction">�ŏ�������֐�f(x)</param>
	///<param name="lowerX">x����</param>
	///<param name="upperX">x���</param>
	///<param name="epsAbs">��Ό덷</param>
	///<param name="epsRel">���Ό덷</param>
	///<param name="maxIter">�ő唽����</param>
	///<param name="xValue">x�̏����l</param>
	ErrorNumber Solve(GSLFunctions::DToD ^ minimizeFunction, double lowerX, double upperX, 
		double epsAbs, double epsRel, int maxIter, double %xValue);

	///<summary>�����v�Z�񐔂��擾����</summary>
	int Iteration(){
		return this->iteration;
	}

private:
	~Minimization();
	gsl_min_fminimizer *minimizer;
	int iteration;

internal:
	GSLFunctions::DToD ^eFnc;

};

double __cdecl minimizationFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Minimization^ min = (Minimization^)gch.Target;
	return min->eFnc(x);
}

}
