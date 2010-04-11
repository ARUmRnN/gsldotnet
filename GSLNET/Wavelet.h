/* Wavelet.h
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

using namespace System::Runtime::InteropServices;

#include <gsl/gsl_wavelet.h>

namespace GSLNET{

public ref class Wavelet
{
public:
	///<summary>�E�F�[�u���b�g�̎��</summary>
	enum class WaveletType {
		///<summary>�h�u�V�E�E�F�[�u���b�g</summary>
		Daubechies,
		///<summary>�n�[���E�E�F�[�u���b�g</summary>
		Haar,
		///<summary>�x�[�^�X�v���C���E�E�F�[�u���b�g</summary>
		BSpline,
	};

	///<summary>����</summary>
	enum class WaveletDirection {
		///<summary>��</summary>
		Forward,
		///<summary>�t</summary>
		Inverse,
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="wType">�E�F�[�u���b�g�̎��</param>
	///<param name="k">�E�F�[�u���b�g�E�t�@�~���[�̃����o�[</param>
	Wavelet(WaveletType wType, size_t k);

	///<summary>�ϊ��������s��</summary>
	///<param name="data">�ϊ�����f�[�^</param>
	///<param name="dir">�ʏ�̕ϊ����t�ϊ���</param>
	int Transform(array<double> ^ %data, WaveletDirection dir);

private:
	~Wavelet();
	gsl_wavelet *wavelet;
	gsl_wavelet_workspace *wSpace;
};

}
