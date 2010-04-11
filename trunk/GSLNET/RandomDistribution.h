/* RandomDistribution.h
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

#include "Rng.h"

namespace GSLNET{

public ref class RandomDistribution
{

public:
	///<summary>���K���������@�̎��</summary>
	enum class GaussianGeneratorType {
		///<summary>�{�b�N�X�E�~���[���[�@</summary>
		BoxMuler,
		///<summary>�}���T�O���A-�c�@���̃W�b�O���g</summary>
		Ziggurat,
		///<summary>�L���_�[�}��-���i�n��-���o�̔�ɂ����@</summary>
		Ratio,
	};

	///<summary>�W���΍��Ђ̐��K������Ԃ�</summary>
	///<param name="gType">���K���������@�̎��</param>
	///<param name="sigma">�W���΍�</param>
	///<param name="random">�����I�u�W�F�N�g</param>
	static double Gaussian(GaussianGeneratorType gType, double sigma, Rng ^ random);

	///<summary>�W���΍��Ђ̐��K���z�̊m�����x�֐��̒l��Ԃ�</summary>
	///<param name="x">x</param>
	///<param name="sigma">�W���΍�</param>
	static double GaussianPdf(double x, double sigma);

private:
	RandomDistribution();

};

}