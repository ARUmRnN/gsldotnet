/* LinearAlgebra.h
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

#include "Matrix.h"
#include "MatrixView.h"
#include "Vector.h"
#include "Permutation.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>���`�㐔�v�Z�N���X</summary>
public ref class LinearAlgebra
{

public:
	///<summary>LU�������s��</summary>
	///<param name="matrix">�s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="signum">�u���̕����i(-1)^n�j</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUDecomposition(Matrix ^ %matrix, Permutation ^ %permutation, [Out] int %signum);

	///<summary>LU�������s��</summary>
	///<param name="matrixView">�s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="signum">�u���̕����i(-1)^n�j</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUDecomposition(MatrixView ^ %matrixView, Permutation ^ %permutation, [Out] int %signum);

	///<summary>LU�������ʂ𗘗p����Ax=b������</summary>
	///<param name="lu">LU�����s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="b">�x�N�g��b</param>
	///<param name="x">��</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ b, Vector ^ %x);

	///<summary>LU�������ʂ𗘗p����Ax=b������</summary>
	///<param name="lu">LU�����s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="x">�x�N�g��b�i���ŏ㏑�������j</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ %x);

	///<summary>LU�������ʂ𗘗p���ċt�s������߂�</summary>
	///<param name="lu">LU�����s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="inverse">�t�s��</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUInvert(Matrix ^ lu, Permutation ^ permutation, Matrix ^ %inverse);

	///<summary>LU�������ʂ𗘗p���ċt�s������߂�</summary>
	///<param name="lu">LU�����s��</param>
	///<param name="permutation">�u���x�N�g��</param>
	///<param name="inverse">�t�s��</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber LUInvert(MatrixView ^ lu, Permutation ^ permutation, MatrixView ^ %inverse);

	///<summary>QR�������s��</summary>
	///<param name="matrix">�s��</param>
	///<param name="tau">�n�E�X�z���_�[�x�N�g��</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber QRDecomposition(Matrix ^ %matrix, Vector ^ %tau);

	///<summary>QR�������ʂ𗘗p����Ax=b������</summary>
	///<param name="qr">QR�����s��</param>
	///<param name="tau">�n�E�X�z���_�[�x�N�g��</param>
	///<param name="b">�x�N�g��b</param>
	///<param name="x">��</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ b, Vector ^ %x);

	///<summary>QR�������ʂ𗘗p����Ax=b������</summary>
	///<param name="qr">QR�����s��</param>
	///<param name="tau">�n�E�X�z���_�[�x�N�g��</param>
	///<param name="x">�x�N�g��b�i���ŏ㏑�������j</param>
	///<returns>�G���[�R�[�h</returns>
	static ErrorNumber QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ %x);

private:
	LinearAlgebra(void);
};

}