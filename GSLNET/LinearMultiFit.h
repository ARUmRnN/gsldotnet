/* LinearMultiFit.h
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

#include <gsl/gsl_multifit.h>
#include "Matrix.h"
#include "Vector.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>�d��A�N���X</summary>
public ref class LinearMultiFit
{
public:
	///<summary>�R���X�g���N�^</summary>
	///<param name="dataNumber">�f�[�^�̐�</param>
	///<param name="variableNumber">�ϐ��̐�</param>
	LinearMultiFit(size_t dataNumber, size_t variableNumber);

	///<summary>�d��A�W�������߂�</summary>
	///<param name="xMatrix">�Ɨ��ϐ��s��</param>
	///<param name="yVector">�]���ϐ��x�N�g��</param>
	///<param name="cov">�d��A�W���̋����U�s��</param>
	///<param name="parameters">�d��A�W��</param>
	///<param name="error">�c�����a</param>
	void GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ %parameters, [Out] double %error);

	///<summary>�d��A�W�������߂�i�d�ݕt���j</summary>
	///<param name="xMatrix">�Ɨ��ϐ��s��</param>
	///<param name="yVector">�]���ϐ��x�N�g��</param>
	///<param name="cov">�d��A�W���̋����U�s��</param>
	///<param name="weight">�d�݃x�N�g��</param>
	///<param name="parameters">�d��A�W��</param>
	///<param name="error">�c�����a</param>
	void GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ weight, Vector ^ %parameters, [Out] double %error);

private:
	~LinearMultiFit();
	gsl_multifit_linear_workspace * wSpace;
};

}