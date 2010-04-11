/* Vector.cpp
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
#include <gsl/gsl_vector.h>

namespace GSLNET{

public ref class Vector
{

private:
	~Vector();

internal:
	gsl_vector * vector;

public:
	///<summary>�R���X�g���N�^</summary>
	///<param name="n">�v�f��</param>
	Vector(size_t n);

	///<summary>�x�N�g���̃T�C�Y���擾����</summary>
	property size_t Size
	{
		size_t get() { return vector->size; }
		private:
			void set(size_t value){}
    }

	///<summary>�v�f�ɒl��ݒ肷��</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="value">�ݒ肷������l</param>
	void SetValue(size_t index, double value);

	///<summary>�S�v�f�ɒl��ݒ肷��</summary>
	///<param name="value">�ݒ肷������l</param>
	void SetValue(double value);

	///<summary>�v�f�ɉ��Z����</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="value">�v�f�ɉ��Z����l</param>
	void AddValue(size_t index, double value);

	///<summary>�v�f���猸�Z����</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<param name="value">�v�f���猸�Z����l</param>
	void SubtractValue(size_t index, double value);

	///<summary>�v�f�̒l���擾����</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<returns>�v�f�̒l</returns>
	double GetValue(size_t index);

	///<summary>�x�N�g�����R�s�[����</summary>
	///<param name="dest">�R�s�[��̃x�N�g��</param>
	void CopyTo(Vector ^ %dest);

	///<summary>�z��ɕϊ�����</summary>
	///<returns>�z��</returns>
	array<double> ^ ToArray();

	///<summary>�z���ǂݍ���</summary>
	///<param name="arr">�z��</param>
	void FromArray(array<double> ^ arr);

};

}