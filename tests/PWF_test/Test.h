#pragma once
#include "Pendulum.h"
#include <iostream>
#include <cassert>
using namespace std; 
//здесь маятник по умолчанию --- создающийся конструктором без аргументов.
class PWF_test {
public: 
	void x1_x0_0_2_w0_0_05_v0_0_2_c_0_0002_t_1(){
		double res;
		res = x1(1,0.0002,0.2,0.05,0.2);
		cout<<"Тестируется функция x1 для t 1, c 0.0002, v 0.2, w0 0.05, x0 0.2\r\n";
		assert(res - 0.399585 < 0.00001);
		cout<<"Успешно\r\n";
	}
	void x2_x0_0_2_w0_0_07_v0_2_c_0_2_t_6(){
		double res;
		res = x2(6,0.2,2,0.07,0.2);
		cout<<"Тестируется функция x1 для t 6, c 0.2, v 2, w0 0.07, x0 0.2\r\n";
		assert(res - 4.61605 < 0.00001);
		cout<<"Успешно\r\n";

	}
	void x3_x0_0_2_w0_1_v0_2_c_1_t_23(){
		double res;
		res = x1(23,1,2,1,0.2);
		cout<<"Тестируется функция x1 для t 23, c 1, v 2, w0 1, x0 0.2\r\n";
		assert(res - 2.05238e-11 < 1e-14);
		cout<<"Успешно\r\n";
	}
};
