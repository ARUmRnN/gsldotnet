/* VectorView.h
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

#include "Vector.h"
#include <gsl/gsl_matrix.h>

namespace GSLNET{

public ref class VectorView
{
private:
	size_t index;
	size_t size;

internal:
	Vector ^ vector;

public:

	///<summary>�v�f�ԍ����擾����</summary>
	property size_t Index
	{
		size_t get() { return index; }
    }

	///<summary>�v�f�����擾����</summary>
	property size_t Size
	{
		size_t get() { return size; }
    }

	///<summary>�R���X�g���N�^</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="size">�v�f��</param>
	VectorView(Vector ^ vector, size_t index, size_t size);

	///<summary>����������</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="size">�v�f��</param>
	void Initialize(Vector ^ vector, size_t index, size_t size);

	///<summary>�v�f�ɒl��ݒ肷��</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="value">�ݒ肷������l</param>
	void SetValue(size_t index, double value);

	///<summary>�v�f�̒l���擾����</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<returns>�v�f�̒l</returns>
	double GetValue(size_t index);

};

}
