/* SurfaceInterpolation.h
 * 
 * Copyright (C) 2009 E.Togashi
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

#include "Interpolation.h"

namespace GSLNET{

public ref class SurfaceInterpolation
{

private:
	Interpolation ^ ipY;
	array<double> ^ yy, ^ zy;
	array<Interpolation^> ^ ips;
	size_t xNumber, yNumber;

public:
	///<summary>X�����̃f�[�^����ݒ�E�擾����</summary>
	property size_t DataNumberX
	{
		size_t get() { return xNumber; }
    }

	///<summary>Y�����̃f�[�^����ݒ�E�擾����</summary>
	property size_t DataNumberY
	{
		size_t get() { return yNumber; }
    }

	SurfaceInterpolation(size_t sizeX, size_t sizeY, Interpolation::Method method);

	///<summary>����������</summary>
	///<param name="x">X�̒l�z��</param>
	///<param name="y">Y�̒l�z��</param>
	///<param name="z">Z�̒l�z��</param>
	void Initialize(array<double> ^ x, array<double> ^ y, array<double, 2> ^ z);

	///<summary>��Ԋ֐��l���v�Z����</summary>
	///<param name="x">X�̒l</param>
	///<param name="y">Y�̒l</param>
	double Evaluate(double x, double y);
};

}