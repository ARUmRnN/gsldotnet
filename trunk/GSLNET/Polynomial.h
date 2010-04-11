/* Polynomial.h
 * 
 * Copyright (C) 2009 E.Togashi
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

#include "Complex.h"
#include "ErrorNumber.h"
#include <gsl/gsl_poly.h>
using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class Polynomial
{

private:
	gsl_poly_complex_workspace * ws;
	double * a, * z;

	///<summary>�f�R���X�g���N�^</summary>
	~Polynomial();

public:
	///<summary>�R���X�g���N�^</summary>
	///<param name="order">�������̎���</param>
	Polynomial(size_t order);

	///<summary>�������̉����v�Z����</summary>
	///<param name="coef">�����W���z��</param>
	///<param name="roots">���̔z��</param>
	///<returns>�����������������ۂ�</returns>
	ErrorNumber Solve(array<double> ^ coef, array<Complex ^> ^ %roots);

	///<summary>�����ϐ�x�̎����W���̑������̒l���v�Z����</summary>
	///<param name="coef">�����W���z��</param>
	///<param name="x">�����ϐ�</param>
	///<returns>�������̒l</returns>
	static double Evaluate(array<double> ^ coef, double x);

	///<summary>���f�ϐ�z�̎����W���̑������̒l���v�Z����</summary>
	///<param name="coef">�����W���z��</param>
	///<param name="z">���f�ϐ�</param>
	///<returns>�������̒l</returns>
	static Complex ^ Evaluate(array<double> ^ coef, Complex z);

	///<summary>���f�ϐ�z�̕��f���W���̑������̒l���v�Z����</summary>
	///<param name="coef">���f���W���z��</param>
	///<param name="z">���f�ϐ�</param>
	///<returns>�������̒l</returns>
	static Complex ^ Evaluate(array<Complex ^> ^ coef, Complex z);

};

}