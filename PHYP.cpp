#include "Pendulum.h"
#include <cmath>
using namespace std;
void getform(form& f, ifstream &f1) {
	string s;
	try {
		f1 >> s;
		if (s == "���") f = ball;
		if (s == "���") f = cube;
		if (s == "�������") f = cilinder;
		if (s == "����") f = disk;
		if (s != "���" && s != "���" && s != "�������" && s != "����") throw "������������ �����: " + s + '\n';
	}
	catch (string s) {
		cerr << s;
		f = none;
	}
	catch (...) {
		cerr << "�������� ������ �������� ������\n";
		f = none;
	}

}
void PhPendulum::put_form(string s) {
	try {
		if (s == "���") f = ball;
		if (s == "���") f = cube;
		if (s == "�������") f = cilinder;
		if (s == "����") f = disk;
		if (f != ball && f != cube && f != cilinder && f != disk) throw "������������ �����: " + s + '\n';
		def();
	}
	catch (string s) {
		cerr << s;
	}
}
void PhPendulum::put_r(double d) {
	try {
		if(d<=0) throw "������ ���� ������ ���� ������������� ������ \n";
		r = d;
		def();
	}
	catch (string s) {
		cerr << s;
	}
}
double PhPendulum::get_r() {
	return r;
}
double PhPendulum::get_J() {
	return J;
}
form PhPendulum::get_form() {
	return f;
}
string PhPendulum::get_form_s() {
	if (f == ball) return "���";
	if (f == cube) return "���";
	if (f == cilinder) return "�������";
	if (f == disk) return "����";
	if (f == none) return "������������";
}
void PhPendulum::def() {
	if (f == ball) {
		J = 0.4*m*r*r;
	}
	if (f == cube) {
		J = 2 * m*r*r / 3;
	}
	if (f == cilinder) {
		J = m*r*r / 2;
	}
	if (f == disk) {
		J = m*r*r / 4;
	}
	L = l + r + J / ((l + r)*m);
	T = 2 * pi*pow(L / g, 0.5);
	w = pow(g / L, 0.5);
	A = pow((x0*x0 + (v0 / w)*(v0 / w)), 0.5);
	if (v0 == 0)
		a = pi / 2;
	else
		a = atan(x0*w / v0);
}
PhPendulum::PhPendulum() {
	f = none;
	r = 0;
}
PhPendulum::PhPendulum(ifstream & f1) {
	try {
		f1 >> x0;
		f1 >> m;
		f1 >> l;
		f1 >> v0;
		getform(f, f1);
		f1 >> r;
		if (r <= 0) throw "������ ���� ������ ���� ������������� ������ \n";
		if (m <= 0) throw "����� �������� ������ ���� ������������� ������ \n";
		if (l <= 0) throw "����� �������� ������ ���� ������������� ������ \n";
		if (f == none)
			SimpleMathPendulum::def();
		else
			def();
	}
	catch (const char* s) {
		existence = false;
		cerr << s;
	}
	catch (...) {
		existence = false;
		cerr << "�������� ������ �������� ������ \n";
	}
}