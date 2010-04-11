/* MatrixView.h
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
#include <gsl/gsl_matrix.h>

namespace GSLNET{

public ref class MatrixView
{
private:
	size_t columnIndex;
	size_t rowIndex;
	size_t rowSize;
	size_t columnSize;

internal:
	Matrix ^ matrix;

public:

	///<summary>�s�ԍ����擾����</summary>
	property size_t ColumnIndex
	{
		size_t get() { return columnIndex; }
    }

	///<summary>��ԍ����擾����</summary>
	property size_t RowIndex
	{
		size_t get() { return rowIndex; }
    }

	///<summary>�s�����擾����</summary>
	property size_t ColumnSize
	{
		size_t get() { return columnSize; }
    }

	///<summary>�񐔂��擾����</summary>
	property size_t RowSize
	{
		size_t get() { return rowSize; }
    }

	///<summary>�R���X�g���N�^</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<param name="columnSize">�s��</param>
	///<param name="rowSize">��</param>
	MatrixView(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize);

	///<summary>����������</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<param name="columnSize">�s��</param>
	///<param name="rowSize">��</param>
	void Initialize(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize);

	///<summary>�s�񐬕����擾����</summary>
	///<param name="rowIndex">�s�ԍ�</param>
	///<param name="columnIndex">��ԍ�</param>
	///<returns>�s�񐬕�(rowIndex, columnIndex)�̒l</returns>
	double GetValue(size_t rowIndex, size_t columnIndex);

	///<summary>�s�񐬕���ݒ肷��</summary>
	///<param name="rowIndex">�s�ԍ�</param>
	///<param name="columnIndex">��ԍ�</param>
	///<param name="value">�s�񐬕�(rowIndex, columnIndex)�̒l</param>
	void SetValue(size_t rowIndex, size_t columnIndex, double value);
};

}
