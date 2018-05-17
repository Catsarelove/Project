#include <iostream>
#include <fstream>
#include "Pendulum.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	string F1, F2;
	cin >> F1 >> F2;
	ifstream f1(F1);
	ofstream f2(F2);
	double t, x = 0, y = 0, f = 0.471239;
	f1 >> t >> f;
	SimpleMathPendulum P1(f1);
	PendulumWFrict P2(f1);
	PhPendulum P3(f1);
	f2 << "���������� �������� ��������������� ��������:\r\n" << P1.x(t) << "\r\n���������� �������� � ������ �������:\r\n" << P2.x(t) << "\r\n���������� ����������� ��������:\r\n" << P3.x(t) << "\r\n";
	P1.Fou(x, y, t, f);
	f2 << "���������� �������� ����:\r\nx = " << x << "; y = " << y << "\r\n";
}