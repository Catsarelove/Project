#include "Pendulum.h"
#include <cmath>
using namespace std;
static double o = 0.00007291158553;
double SimpleMathPendulum::get_w(){
	return w;
}
double SimpleMathPendulum::get_T(){
	return T;
}
double SimpleMathPendulum::x(double t) {
	if (existence)
		return A*sin(w*t + a);
	cerr << "Маятник не существует \n";
	return NULL;
}
void SimpleMathPendulum::def() {
	T = 2 * pi*pow(l / g, 0.5);
	w = pow(g / l, 0.5);
	A = pow((x0*x0 + (v0 / w)*(v0 / w)), 0.5);
	if (v0 == 0)
		a = pi / 2;
	else
		a = atan(x0*w / v0);
}
SimpleMathPendulum::SimpleMathPendulum() {
	x0 = 1;
	v0 = 0;
	m = 0.1;
	l = 5;
	def();
}
SimpleMathPendulum::SimpleMathPendulum(ifstream & f1) {
	try {
		f1 >> x0;
		f1 >> m;
		f1 >> l;
		f1 >> v0;
		if (m <= 0) throw "Масса маятника должна быть положительным числом \n";
		if (l <= 0) throw "Длина маятника должна быть положительным числом \n";
		def();
	}
	catch (const char* s) {
		cout << s;
		existence = false;
	}
	catch (...) {
		cout << "Неверный формат исходных данных \n";
		existence = false;
	}
}

void SimpleMathPendulum::Fou(double &x, double &y, double t, double f) {
	if (existence) {
		double p = 0; double tt = 0;
		double w1 = pow(w*w + pow(o*sin(f), 2), 0.5);
		tt = o*sin(f)*t;
		double i, j;
		if (x0) {
			i = atan((w1*cos(tt)) / (v0 / x0 + o*sin(f)*sin(tt)));
			if (sin(i))
				j = x0 / sin(i);
			else j = 0;
		}
		else {
			i = 0;
			j = v0 / (w1*cos(tt));
		}
		p = j*sin(w1*t+i);
		x = p*cos(tt);
		y = p*sin(tt);
	}
	else {
		x = y = 0;
		cout << "Маятник не существует \n";
	}
}