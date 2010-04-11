/* Blas.h
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
#include <gsl/gsl_blas.h>
#include "Vector.h"
#include "Matrix.h"
#include "VectorView.h"
#include "MatrixView.h"

namespace GSLNET{

public ref class Blas
{
public:
	///<summary>�]�u�̎��</summary>
	enum class TransposeType {
		///<summary>�]�u����</summary>
		NoTranspose,
		///<summary>�]�u�s��</summary>
		TransPose,
		///<summary>����]�u�s��</summary>
		ConjugateTranspose,
	};

	///<summary>�s��ƍs��̐ςƘa���v�Z����iC = �� op(A) op(B) + ��C�j</summary>
	///<param name="transA">�s��A�̓]�u���</param>
	///<param name="transB">�s��B�̓]�u���</param>
	///<param name="alpha">��ꍀ�̌W��</param>
	///<param name="mA">�s��A</param>
	///<param name="mB">�s��B</param>
	///<param name="beta">��񍀂̌W��</param>
	///<param name="mC">�s��C�i�����㏑�������j</param>
	static void DGemm(TransposeType transA, TransposeType transB, double alpha, const Matrix ^ mA, const Matrix ^ mB, double beta, Matrix ^ %mC);

	///<summary>�s��ƍs��̐ςƘa���v�Z����iC = �� op(A) op(B) + ��C�j</summary>
	///<param name="transA">�s��A�̓]�u���</param>
	///<param name="transB">�s��B�̓]�u���</param>
	///<param name="alpha">��ꍀ�̌W��</param>
	///<param name="mA">�s��A</param>
	///<param name="mB">�s��B</param>
	///<param name="beta">��񍀂̌W��</param>
	///<param name="mC">�s��C�i�����㏑�������j</param>
	static void DGemm(TransposeType transA, TransposeType transB, double alpha, MatrixView ^ mA, MatrixView ^ mB, double beta, MatrixView ^ %mC);

	///<summary>�s��ƃx�N�g���̐ςƘa���v�Z����iy = �� op(A) x + ��y�j</summary>
	///<param name="transA">�s��A�̓]�u���</param>
	///<param name="alpha">��ꍀ�̌W��</param>
	///<param name="mA">�s��A</param>
	///<param name="vX">�x�N�g��X</param>
	///<param name="beta">��񍀂̌W��</param>
	///<param name="vY">�x�N�g��Y�i�����㏑�������j</param>
	static void DGemv(TransposeType transA, double alpha, const Matrix ^ mA, const Vector ^ vX, double beta, Vector ^ %vY);

	///<summary>�s��ƃx�N�g���̐ςƘa���v�Z����iy = �� op(A) x + ��y�j</summary>
	///<param name="transA">�s��A�̓]�u���</param>
	///<param name="alpha">��ꍀ�̌W��</param>
	///<param name="mA">�s��A</param>
	///<param name="vX">�x�N�g��X</param>
	///<param name="beta">��񍀂̌W��</param>
	///<param name="vY">�x�N�g��Y�i�����㏑�������j</param>
	static void DGemv(TransposeType transA, double alpha, MatrixView ^ mA, VectorView ^ vX, double beta, VectorView ^ %vY);

private:
	Blas(void);
	static CBLAS_TRANSPOSE_t getTrns(TransposeType tType);
};

}