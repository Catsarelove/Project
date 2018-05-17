#pragma once
#include "Pendulum.h"
#include <iostream>
#include <cassert>
using namespace std; 
//здесь маятник по умолчанию --- создающийся конструктором без аргументов.
class SMP_test {
public: 
	void Foucalt_default_pen_t_1_01695_561e_06(){ 
		SimpleMathPendulum P;
		double x = 0, y = 0;
		P.Fou(x, y, 1, 0.471239);
		cout<<"Тестируется функция Fou для маятника по умолчанию t=1\r\n";
		assert(x-0.169499<0.00001 && y-5.61062e-06<0.00001);
		cout<<"Успешно\r\n";
	}
	void Foucalt_x0_1_v0_0_5_m_0_1_l_15_t_1(){
		SimpleMathPendulum P;
		P.put_x0(1);
		P.put_v0(0.5);
		P.put_m(0.1);
		P.put_l(15);
		double x = 0, y = 0;
		P.Fou(x, y, 1, 0.471239);
		cout<<"Тестируется функция Fou для маятника 1/0.5/0.1/15 t=1\r\n";
		assert(x-1.13781<0.00001 && y-3.76628e-05<0.00001);
		cout<<"Успешно\r\n";
	}
	void Foucalt_x0_0_v0_2_m_0_1_l_15_t_2(){
		SimpleMathPendulum P;
		P.put_x0(0);
		P.put_v0(2);
		P.put_m(0.1);
		P.put_l(15);
		double x = 0, y = 0;
		P.Fou(x, y, 2, 0.471239);
		cout<<"Тестируется функция Fou для маятника 0/2/0.1/15 t=2\r\n";
		assert(x-2.47086<0.00001 && y-0.000163577<0.00001);
		cout<<"Успешно\r\n";
	}
	void x_x0_0_v0_2_m_0_1_l_15_t_2(){
		SimpleMathPendulum P;
		P.put_x0(0);
		P.put_v0(2);
		P.put_m(0.1);
		P.put_l(15);
		double res=P.x(2);
		cout<<"Тестируется функция x для маятника 0/2/0.1/15 t=2\r\n";
		assert(res-2.47086<0.00001);
		cout<<"Успешно\r\n";
	}
};
