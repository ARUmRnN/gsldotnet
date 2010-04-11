/* Complex.h
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
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

namespace GSLNET{

public ref class Complex
{
internal:
	gsl_complex * cmplx;

public:
	///<summary>�R���X�g���N�^</summary>
	Complex(void);

	///<summary>�f�R���X�g���N�^</summary>
	~Complex();

	///<summary>������ݒ�E�擾����</summary>
	property double RealPart
	{
		double get() { return GSL_REAL(*cmplx); }
		void set(double value){ GSL_SET_REAL(cmplx, value);}
    }

	///<summary>������ݒ�E�擾����</summary>
	property double ImaginaryPart
	{
		double get() { return GSL_IMAG(*cmplx); }
		void set(double value){ GSL_SET_IMAG(cmplx, value);}
    }

	///<summary>�������W�n�ł̍��W�l��^���ĕ��f�����쐬����</summary>
	///<param name="x">�������W�n�ł�x</param>
	///<param name="y">�������W�n�ł�y</param>
	///<returns>���f���I�u�W�F�N�g</returns>
	static Complex ^ Rect(double x, double y);

	///<summary>�ɍ��W�n�ł̍��W�l��^���ĕ��f�����쐬����</summary>
	///<param name="r">�ɍ��W�n�ł�r</param>
	///<param name="theta">�ɍ��W�n�ł�theta</param>
	///<returns>���f���I�u�W�F�N�g</returns>
	static Complex ^ Polar(double r, double theta);

};

}