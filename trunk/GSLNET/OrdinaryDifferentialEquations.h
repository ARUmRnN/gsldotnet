/* OrdinaryDifferentialEquations.h
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
#include "GSLFunctions.h"
#include "Jacobian.h"
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_vector.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class OrdinaryDifferentialEquations
{
public:
	///<summary>������������̉�@�̎��</summary>
	enum class SolverType {
		///<summary>���ߍ��݌^RK23����</summary>
		RungeKutta2,
		///<summary>�l���̃����Q�E�N�b�^�@</summary>
		RungeKutta4,
		///<summary>���ߍ��݌^RKF45����</summary>
		RungeKuttaFehlberg,
		///<summary>���ߍ��݌^RKCK45����</summary>
		RungeKuttCashKarp,
		///<summary>���ߍ��݌^RKPD89����</summary>
		RungeKuttaPrinceDormand,
		///<summary>�񎟂̉A�I�����Q�E�N�b�^�@</summary>
		ImplicitRungeKutta2,
		///<summary>�l���̉A�I�����Q�E�N�b�^�@</summary>
		ImplicitRungeKutta4,
		///<summary>�A�I�u�����V���E�X�g�A�@</summary>
		BulirschStoer,
		///<summary>M=1�̉A�I�M�A�@</summary>
		ImplicitGear1,
		///<summary>M=2�̉A�I�M�A�@</summary>
		ImplicitGear2,
	};

	///<summary>�R���X�g���N�^</summary>
	///<param name="sType">������������̉�@�̎��</param>
	///<param name="dimension">����</param>
	OrdinaryDifferentialEquations(SolverType sType, int dimension);

	///<summary>������������̉�@�̎�ނ��擾����</summary>
	property SolverType Solver {
        SolverType get() { return this->sType; }
    }

	///<summary>�W���̃X�e�b�v�������֐���ݒ肷��</summary>
	///<param name="eps_abs">��Ό덷</param>
	///<param name="eps_rel">���Ό덷</param>
	///<param name="a_y">��y(t)�ɑ΂���X�P�[�����O�W��</param>
	///<param name="a_dydt">���֐�y'(t)�ɑ΂���X�P�[�����O�W��</param>
	void SetStandardControl(double eps_abs, double eps_rel, double a_y, double a_dydt);

	///<summary>���̒l�ɑ΂���덷�Ɋ�Â��ăX�e�b�v���������s���悤�ɐݒ肷��</summary>
	///<param name="eps_abs">��Ό덷</param>
	///<param name="eps_rel">���Ό덷</param>
	void SetYControl(double eps_abs, double eps_rel);

	///<summary>���̔����l�ɑ΂���덷�Ɋ�Â��ăX�e�b�v���������s���悤�ɐݒ肷��</summary>
	///<param name="eps_abs">��Ό덷</param>
	///<param name="eps_rel">���Ό덷</param>
	void SetYPControl(double eps_abs, double eps_rel);

	///<summary>�X�P�[�����O���̃X�e�b�v�������֐���ݒ肷��</summary>
	///<param name="eps_abs">��Ό덷</param>
	///<param name="eps_rel">���Ό덷</param>
	///<param name="a_y">��y(t)�ɑ΂���X�P�[�����O�W��</param>
	///<param name="a_dydt">���֐�y'(t)�ɑ΂���X�P�[�����O�W��</param>
	///<param name="scale">�e�v�f�ɑ΂���X�P�[�����O�z��</param>
	void SetScaledControl(double eps_abs, double eps_rel, double a_y, double a_dydt, array<double> ^ scale);

	///<summary>�����l��������</summary>
	///<param name="eFnc">�����l�v�Z�֐�</param>
	///<param name="initialTime">��������</param>
	///<param name="endTime">�ŏI����</param>
	///<param name="initialTStep">������T</param>
	///<param name="variables">��ԕϐ������l</param>
	ErrorNumber Solve(GSLFunctions::TDArrayToDArray ^eFnc, double %initialTime, double endTime, double %initialTStep, array<double> ^ %variables, [Out] int %iterNum);

	///<summary>�r���o�ߏ����o������</summary>
	GSLFunctions::TDArray ^ IntermediateOutput;

private:
	int dimension;
	~OrdinaryDifferentialEquations();
	gsl_odeiv_step *fSolver;
	SolverType sType;
	gsl_odeiv_control *odeCtrl;
	gsl_odeiv_evolve *evolve;
	double * yVector;

internal:
	GSLFunctions::TDArrayToDArray ^eFnc;
	array<double>^ inputs;
	array<double>^ outputs;
	array<double>^ dydt;
	array<array<double>^>^ jacobian;
};

int __cdecl odeErrorFunction (double t, const double y[], double dydt[], void* params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	OrdinaryDifferentialEquations^ ode = (OrdinaryDifferentialEquations^)gch.Target;

	array<double>^ inputs = ode->inputs;
	array<double>^ outputs= ode->outputs;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = y[i];
	}

	ode->eFnc(t, inputs, outputs);

	for(int i=0;i<dimension;i++){
		dydt[i] = outputs[i];
	}

	return GSL_SUCCESS;
}

int __cdecl odeErrorFunctionFD(double t, const double y[], double * dfdy, double dydt[], void* params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	OrdinaryDifferentialEquations^ ode = (OrdinaryDifferentialEquations^)gch.Target;

	array<double>^ inputs = ode->inputs;
	array<double>^ outputs= ode->outputs;
	array<array<double>^>^ jacobian = ode->jacobian;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = y[i];
	}

	Jacobian::Calculate(ode->eFnc, t, inputs, ode->jacobian, ode->dydt);

	int counter=0;
	for(int i=0;i<dimension;i++){
		dydt[i] = ode->dydt[i];
		for(int j=0;j<dimension;j++){
			dfdy[counter] = ode->jacobian[j][i];
			counter++;
		}
	}

	return GSL_SUCCESS;
}

}