/* Jacobian.h
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

#include "GSLFunctions.h"
#include "ErrorNumber.h"

namespace GSLNET{

public ref class Jacobian
{

public:

	///<summary>���R�r�s����v�Z����</summary>
	///<param name="fnc">�o�̓x�N�g���im�����j�v�Z�֐�</param>
	///<param name="inputs">���̓x�N�g���in�����j</param>
	///<param name="jacobian">���R�r�s��in�~m�����j</param>
	static void Calculate(GSLFunctions::DArrayToDArray ^ fnc, array<double> ^ inputs, array<array<double>^>^ %jacobian);

	///<summary>���R�r�s����v�Z����</summary>
	///<param name="fnc">�o�̓x�N�g���im�����j�v�Z�֐�</param>
	///<param name="fnc">����</param>
	///<param name="inputs">���̓x�N�g���in�����j</param>
	///<param name="jacobian">���R�r�s��in�~m�����j</param>
	///<param name="dydt">���Ԃɑ΂���o�͔����x�N�g��</param>
	static void Calculate(GSLFunctions::TDArrayToDArray ^ fnc, double t, array<double> ^ inputs, array<array<double>^>^ %jacobian, array<double> ^ %dydt);

	///<summary>���R�r�s��v�Z�p�L�������l��ݒ�E�擾����</summary>
	static double Delta = 1e-7;

private:
	Jacobian(void);
};

}