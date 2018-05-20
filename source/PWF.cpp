#include "Pendulum.h"
#include <cmath>
using namespace std;
double x1(double t, double c, double v0, double w0, double x0) {
	double A;
	double w = pow(w0*w0 - c*c, 0.5);
	A = pow((x0*x0 + pow((v0 + c*x0)/(w),2)), 0.5);
	double a;
	if (A == 0)
		a = 0;
	else
		a = asin(x0/A);
	return A*exp(-c*t)*sin(w*t + a);
}
double x2(double t, double c, double v0, double w0, double x0) {

	double a1 = c + pow(c*c - w0*w0, 0.5);
	double a2 = c - pow(c*c - w0*w0, 0.5);
	double C2 = (v0 + a1*x0) / (a1 - a2);
	double C1 = x0 - C2;
	return C1*exp(-a1*t) + C2*exp(-a2*t);

}
double x3(double t, double c, double v0, double w0, double x0) {
	double C1 = x0*c + v0;
	double C2 = x0;
	return (C1*t + C2)*exp(-c*t);
}

void PendulumWFrict::def() {
	w0 = pow(g / l, 0.5);
	A = pow((x0*x0 + (v0 / w0)*(v0 / w0)), 0.5);
	if (v0 == 0)
		a = pi / 2;
	else
		a = atan(x0*w0 / v0);
	c = k / (2 * m);
	if (m*g*sin(a) <= k*v0) {
		xt = NULL;
		v0 = 0;
	}
	else {
		if (w0 > c)
			xt = x1;
		if (w0 == c)
			xt = x2;
		if (w0 < c)
			xt = x3;
	}
}
PendulumWFrict::PendulumWFrict() {
	x0 = 1;
	v0 = 0;
	m = 0.1;
	l = 5;
	k = 0;
	def();
}
PendulumWFrict::PendulumWFrict(ifstream & f1) {
	try {
		f1 >> x0;
		f1 >> m;
		f1 >> l;
		f1 >> v0;
		f1 >> k;
		if (m <= 0) throw "Ěŕńńŕ ěŕ˙ňíčęŕ äîëćíŕ áűňü ďîëîćčňĺëüíűě ÷čńëîě\n";
		if (l <= 0) throw "Äëčíŕ ěŕ˙ňíčęŕ äîëćíŕ áűňü ďîëîćčňĺëüíűě ÷čńëîě\n";
		if (k < 0) throw "Â˙çęîńňü äîëćíŕ áűňü íĺîňđčöŕňĺëüíűě ÷čńëîě\n";
		def();
	}
	catch (const char* s) {
		existence = false;
		cerr << s;
	}
	catch (...) {
		cerr << "Íĺâĺđíűé ôîđěŕň čńőîäíűő äŕííűő \n";
		existence = false;
	}
}
void PendulumWFrict::put_k(double d) {
	try {
		if(d<0) throw "Â˙çęîńňü äîëćíŕ áűňü íĺîňđčöŕňĺëüíűě ÷čńëîě\n";
		k = d;
		def();
	}
	catch (const char* s) {
		cerr << s;
	}
}
double PendulumWFrict::get_k() {
	return k;
}
double PendulumWFrict::get_A(double t = 0) {
	return  A*exp(-c*t);
}
double PendulumWFrict::x(double t) {
	if (existence) {
		if (xt == NULL) return x0;
		return xt(t, c, v0, w0, x0);
	}
	cout << "Ěŕ˙ňíčę íĺ ńóůĺńňâóĺň \n";
	return NULL;
}
