/* Rng.h
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

#include <gsl/gsl_rng.h>

namespace GSLNET{

public ref class Rng
{

public:
	///<summary>����������̎��</summary>
	enum class GeneratorType {
		///<summary>�����Z���k�E�c�C�X�^�[</summary>
		MT19937,
		///<summary>Luxury Random Numbers Level1</summary>
		Ranlux1,
		///<summary>Luxury Random Numbers Level2</summary>
		Ranlux2,
		///<summary>�����b�V���|�̕��@</summary>
		Ranlux389,
		///<summary>���L���G���̏d�ċN��������������</summary>
		CombinedMultipleRecursive,
		///<summary>���L���G���̏d�ċN��������������i�܎��j</summary>
		MultipleRecursive,
		///<summary>�^�E�X���[�X�^����������</summary>
		Taus,
		///<summary>�^�E�X���[�X�^����������2</summary>
		Taus2,		
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="gType">����������̎��</param>
	Rng(GeneratorType gType);

	///<summary>�R���X�g���N�^</summary>
	///<param name="gType">����������̎��</param>
	///<param name="s">�����̎�</param>
	Rng(GeneratorType gType, unsigned long int s);

	///<summary>0~1�͈̔͂Ɉ�l�ɕ��z���闐�����쐬����</summary>
	double Uniform();

internal:
	gsl_rng * rnd;

};

}