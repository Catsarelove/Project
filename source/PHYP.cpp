#include "Pendulum.h"
#include <cmath>
using namespace std;
void getform(form& f, ifstream &f1) {
	string s;
	try {
		f1 >> s;
		if (s == "øàð") f = ball;
		if (s == "êóá") f = cube;
		if (s == "öèëèíäð") f = cilinder;
		if (s == "äèñê") f = disk;
		if (s != "øàð" && s != "êóá" && s != "öèëèíäð" && s != "äèñê") throw "Íåîïîçíàííàÿ ôîðìà: " + s + '\n';
	}
	catch (string s) {
		cerr << s;
		f = none;
	}
	catch (...) {
		cerr << "Íåâåðíûé ôîðìàò èñõîäíûõ äàííûõ\n";
		f = none;
	}

}
void PhPendulum::put_form(string s) {
	try {
		if (s == "øàð") f = ball;
		if (s == "êóá") f = cube;
		if (s == "öèëèíäð") f = cilinder;
		if (s == "äèñê") f = disk;
		if (f != ball && f != cube && f != cilinder && f != disk) throw "Íåîïîçíàííàÿ ôîðìà: " + s + '\n';
		def();
	}
	catch (string s) {
		cerr << s;
	}
}
void PhPendulum::put_r(double d) {
	try {
		if(d<=0) throw "Ðàäèóñ òåëà äîëæíà áûòü ïîëîæèòåëüíûì ÷èñëîì \n";
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
	if (f == ball) return "øàð";
	if (f == cube) return "êóá";
	if (f == cilinder) return "öèëèíäð";
	if (f == disk) return "äèñê";
	if (f == none) return "áåñôîðìåííûé";
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
		if (r <= 0) throw "Ðàäèóñ òåëà äîëæíà áûòü ïîëîæèòåëüíûì ÷èñëîì \n";
		if (m <= 0) throw "Ìàññà ìàÿòíèêà äîëæíà áûòü ïîëîæèòåëüíûì ÷èñëîì \n";
		if (l <= 0) throw "Äëèíà ìàÿòíèêà äîëæíà áûòü ïîëîæèòåëüíûì ÷èñëîì \n";
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
		cerr << "Íåâåðíûé ôîðìàò èñõîäíûõ äàííûõ \n";
	}
}
