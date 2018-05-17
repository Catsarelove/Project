#pragma once
#include "Pendulum.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std; 
//здесь маятник по умолчанию --- создающийся конструктором без аргументов.
class PHYP_test {
public: 
	void getform_cube(){
		ifstream f1("test_in_cube.txt");
		form res;
		getform(res, f1);
		f1.close();
		cout<<"Тестируется getform, куб \r\n";
		assert(res == cube);
		cout<<"Успешно\r\n";
	}
		void getform_none(){
		ifstream f1("test_in_none.txt");
		form res=cube;
		getform(res, f1);
		if(res==cube) cout<<"sss";
		f1.close();
		cout<<"Тестируется getform, нет\r\n";
		assert(res == none);
		cout<<"Успешно\r\n";
	}
};
