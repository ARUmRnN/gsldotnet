/* Permutation.h
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

#include <gsl/gsl_permutation.h>

namespace GSLNET{

///<summary>�u���x�N�g���N���X</summary>
public ref class Permutation
{
public:
	///<summary>�R���X�g���N�^</summary>
	///<param name="n">�u���x�N�g���̎���</param>
	Permutation(size_t n);

	///<summary>�R���X�g���N�^</summary>
	///<param name="n">�u���x�N�g���̎���</param>
	///<param name="initVector">�P���u���ƂȂ�悤�ɏ��������邩</param>
	Permutation(size_t n, bool initVector);

	///<summary>�u���x�N�g���̃T�C�Y���擾����</summary>
	property size_t Size
	{
        size_t get() { return gsl_permutation_size(permutation); }
		private:
			void set(size_t value){}
    }

	///<summary>�P���u���ƂȂ�悤�ɏ���������</summary>
	void Initialize();

	///<summary>�u���x�N�g�����R�s�[����</summary>
	///<param name="target">�R�s�[��̒u���x�N�g���i����������Ă���K�v������j</param>
	void Copy(Permutation %target);

	///<summary>�v�f���擾����</summary>
	///<param name="index">�v�f�ԍ�</param>
	///<returns>�v�f�̒l</returns>
	size_t GetValue(size_t index);

	///<summary>�v�f�����ւ���</summary>
	///<param name="i">�v�f1</param>
	///<param name="j">�v�f2</param>
	void Swap(size_t i, size_t j);

	///<summary>�v�f���t�ɂ���</summary>
	void Reverse();

	///<summary>�t�u�����v�Z����inv�ɐݒ肷��</summary>
	///<param name="inv">�t�u��</param>
	void Inverse(Permutation inv);

	///<summary>�������Ŏ��̒u���ɐi��</summary>
	///<returns>���̒u��������ꍇ�͐^</returns>
	bool Next();

	///<summary>�������őO�̒u���ɖ߂�</summary>
	///<returns>�O�̒u��������ꍇ�͐^</returns>
	bool Prev();

private:
	~Permutation();

internal:
	gsl_permutation *permutation;

};

}