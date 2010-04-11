/* GSLFunctions.h
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

#include "ErrorNumber.h"

namespace GSLNET{

public ref class GSLFunctions
{
public:

	///<summary>���̓x�N�g������o�̓x�N�g�����v�Z����֐�</summary>
	///<param name="inputs">���̓x�N�g��</param>
	///<param name="outputs">�o�̓x�N�g��</param>
	delegate GSLNET::ErrorNumber DArrayToDArray(array<double> ^ inputs, array<double> ^ %outputs);

	///<summary>�����Ɠ��̓x�N�g������o�̓x�N�g�����v�Z����֐�</summary>
	///<param name="t">����</param>
	///<param name="inputs">���̓x�N�g��</param>
	///<param name="outputs">�o�̓x�N�g��</param>
	delegate GSLNET::ErrorNumber TDArrayToDArray(double t, array<double> ^ inputs, array<double> ^ %outputs);

	///<summary>�����Ɠ��̓x�N�g����^����֐�</summary>
	///<param name="t">����</param>
	///<param name="inputs">���̓x�N�g��</param>
	delegate void TDArray(double t, array<double> ^ inputs);

	///<summary>�����l���͂�������l�o�͂��v�Z����֐�</summary>
	///<param name="input">�����l����</param>
	///<returns>�����l�o��</returns>
	delegate double DToD(double input);

};

}