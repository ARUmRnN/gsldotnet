/* Matrix.h
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

#include <gsl/gsl_matrix.h>

namespace GSLNET{

public ref class Matrix
{

private:
	~Matrix();
	Matrix(gsl_matrix *mat);

internal:
	gsl_matrix * matrix;

public:
	///<summary>�R���X�g���N�^</summary>
	///<param name="columnNumber">��</param>
	///<param name="rowNumber">�s��</param>
	Matrix(size_t columnNumber, size_t rowNumber);

	///<summary>�񐔂��擾����</summary>
	property size_t Rows
	{
		size_t get() { return (*matrix).size2; }
		private:
			void set(size_t value){}
    }

	///<summary>�s�����擾����</summary>
	property size_t Columns
	{
		size_t get() { return (*matrix).size1; }
		private:
			void set(size_t value){}
    }

	///<summary>�s�񐬕����擾����</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<returns>�s�񐬕�(rowIndex, columnIndex)�̒l</returns>
	double GetValue(size_t columnIndex, size_t rowIndex);

	///<summary>�s�񐬕���ݒ肷��</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<param name="value">�s�񐬕�(columnIndex, rowIndex)�̒l</param>
	void SetValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>�s�񐬕��ɉ��Z����</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<param name="value">�s�񐬕�(columnIndex, rowIndex)�ɉ��Z����l</param>
	void AddValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>�s�񐬕����猸�Z����</summary>
	///<param name="columnIndex">�s�ԍ�</param>
	///<param name="rowIndex">��ԍ�</param>
	///<param name="value">�s�񐬕�(columnIndex, rowIndex)���猸�Z����l</param>
	void SubtractValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>���ׂĂ̍s�񐬕��̒l������������</summary>
	///<param name="value">����������l</param>
	void InitializeValue(double value);

	///<summary>�P�ʍs��ɂ���</summary>
	void MakeUnitMatrix();

	///<summary>�z��ɕϊ�����</summary>
	///<returns>�z��</returns>
	array<double, 2> ^ ToArray();

};

}