#include "Pendulum.h"
#include <cmath>
using namespace std;
//äîîďđĺäĺëč ôóíęöčč äë˙ áŕçîâîăî ęëŕńńŕ
void Pendulum::put_x0(double d) {
	x0 = d;
	def();
}
void Pendulum::put_v0(double d) {
	v0 = d;
	def();
}
void Pendulum::put_m(double d) {
	try {
		if (d <= 0) throw "Ěŕńńŕ ěŕ˙ňíčęŕ äîëćíŕ áűňü ďîëîćčňĺëüíűě ÷čńëîě\n";
		m = d;
		def();
	}
	catch (const char* s) {
		cerr << s;
	}
}
void Pendulum::put_l(double d) {
	try {
		if (d <= 0) throw "Äëčíŕ ěŕ˙ňíčęŕ äîëćíŕ áűňü ďîëîćčňĺëüíűě ÷čńëîě\n";
		l = d;
		def();
	}
	catch (const char* s) {
		cerr << s;
	}
}
double Pendulum::get_x0() {
	return x0;
}
double Pendulum::get_v0() {
	return v0;
}
double Pendulum::get_m() {
	return m;
}
double Pendulum::get_l() {
	return l;
}
double Pendulum::get_a() {
	return a;
}
double Pendulum::get_A() {
	return A;
}
