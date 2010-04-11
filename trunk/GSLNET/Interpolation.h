/* Interpolation.h
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

#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>

namespace GSLNET{

public ref class Interpolation
{
private:
	size_t number;
	gsl_spline * spline;
	gsl_interp_accel * acc;
	double *x, *y;
	~Interpolation();

public:
	///<summary>�ۊǖ@�̎��</summary>
	enum class Method {
		///<summary>���`���</summary>
		Linear,
		///<summary>���������</summary>
		Polynomial,
		///<summary>���R���E�ł̎O���X�v���C��</summary>
		CSpline,
		///<summary>�����I���E�̎O���X�v���C��</summary>
		CSpline_Periodic,
		///<summary>���R���E�ł̏H�ԃX�v���C��</summary>
		Akima,
		///<summary>�����I���E�����ł̏H�ԃX�v���C��</summary>
		Akima_Periodic
	};

	///<summary>�f�[�^����ݒ�E�擾����</summary>
	property size_t DataNumber
	{
		size_t get() { return number; }
    }

	///<summary>�R���X�g���N�^</summary>
	///<param name="size">�f�[�^��</param>
	///<param name="method">��Ԏ�@</param>
	Interpolation(size_t size, Method method);

	///<summary>����������</summary>
	///<param name="x">X�̒l�z��</param>
	///<param name="y">Y�̒l�z��</param>
	void Initialize(array<double> ^ x, array<double> ^ y);

	///<summary>��Ԋ֐��l���v�Z����</summary>
	///<param name="x">��Ԉʒu</param>
	double Evaluate(double x);

	///<summary>��Ԋ֐��̔����l���v�Z����</summary>
	///<param name="x">��Ԉʒu</param>
	double EvaluateDerivative(double x);

	///<summary>��Ԋ֐��̓�K�����l���v�Z����</summary>
	///<param name="x">��Ԉʒu</param>
	double EvaluateDerivative2(double x);

	///<summary>��Ԋ֐��̐ϕ��l���v�Z����</summary>
	///<param name="x1">�ϕ���ԊJ�n�ʒu</param>
	///<param name="x2">�ϕ���ԏI���ʒu</param>
	double EvaluateIntegral(double x1, double x2);

};

}