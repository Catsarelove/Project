#ifndef __HEADER_H__
#define __HEADER_H__
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
static const double g = 9.80665;
static const double pi = 3.1415926535;
void Foucault(double, double, double, double, double &, double &);
class Pendulum {
protected: bool existence = true;
	double x0; // íŕ÷ŕëüíŕ˙ ęîîđäčíŕňŕ
	double v0; //íŕ÷ŕëüíŕ˙ ńęîđîńňü
	double m; //ěŕńńŕ ěŕ˙ňíčęŕ
	double l; //äëčíŕ ďîäâĺńŕ
	double a; //óăîë íŕ÷ŕëüíîăî îňęëîíĺíč˙
	double A; //ŕěďëčňóäŕ
	virtual void def() = 0;
public:
	void put_x0(double d);
	void put_v0(double d);
	void put_m(double d);
	void put_l(double d);
	double get_x0();
	double get_v0();
	double get_m();
	double get_l();
	double get_a();
	double get_A();
	virtual double x(double t) = 0;
};

class SimpleMathPendulum : public Pendulum {
protected:
	double T; //ďĺđčîä ęîëĺáŕíčé
	double w; //÷ŕńňîňŕ ęîëĺáŕíčé
	void def();
public:
	SimpleMathPendulum();
	SimpleMathPendulum(ifstream & f1);
	double get_w();
	double get_T();
	double x(double t);
	void Fou(double &x, double &y, double t, double f);
};

typedef enum { ball, cube, cilinder, disk, none } form;
void getform(form& f, ifstream &f1);
class PhPendulum : public SimpleMathPendulum {
private:	
	void def();
	form f;
	double r; //đŕäčóń řŕđŕ, đŕäčóń öčëčíäđŕ, ńňîđîíŕ ęóáŕ, ěŕëűé đŕäčóń äčńęŕ
	double J;// ěîěĺíň čěďóëüńŕ
	double L;//ďđčâĺäĺííŕ˙ äëčíŕ
public:
	void put_form(string s);
	void put_r(double d);
	double get_r();
	double get_J();
	form get_form();
	string get_form_s();
	PhPendulum();
	PhPendulum(ifstream & f1);
};

typedef double(*ft)(double, double, double, double, double);
double x1(double, double, double, double, double);
double x2(double, double, double, double, double);
double x3(double, double, double, double, double);
class PendulumWFrict :public Pendulum {
private:
	double w0;
	double c;
	double k;
	ft xt;
	void def();
public:
	double get_A(double t);
	void put_k(double d);
	double get_k();
	PendulumWFrict();
	PendulumWFrict(ifstream & f1);
	double x(double t);
};
#endif
