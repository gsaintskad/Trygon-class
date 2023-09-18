#include "angle.h"
#include<iostream>
#include<string>
#include<math.h>
#include<string>
#include <windows.h>
#define pi 3.14159265358979323846
using namespace std;
	angle::angle() {
		radian = 0;
		degree = 0;
		fault = 0.00001;
	}
	angle::angle(bool type, double value) {
		radian = value;
		degree = radian * 180 / pi;
		fault = 0.00001;
	}
	angle::angle(double value) {
		degree = value;
		radian = degree / 180 * pi;
		fault = 0.00001;
	}
	void angle::showValue() {
		cout << "angle.degree\t" << degree << endl;
		cout << "angle.radian\t" << radian << endl;
	}
	void angle::recount(bool type, double value) {
		if (!type) {
			radian = value;
			degree = radian * 180 / pi;
		}
		else {
			degree = value;
			radian = degree / 180 * pi;
		}
	}
	void angle::recount(double value) {
		degree = value;
		radian = degree / 180 * pi;
	}

	angle angle::operator =(const angle& alfa) {
		this->degree = alfa.degree;
		this->radian = alfa.radian;
		return *this;
	}
	bool angle::operator ==(const angle& gamma) {
		if ((this->degree + fault) >= gamma.degree && (this->degree - fault) <= gamma.degree) {
			return 1;
		}
		else
			return 0;
	}
	bool angle::operator ==(const double& gamma) {
		if ((this->degree + fault) >= gamma && (this->degree - fault) <= gamma) {
			return 1;
		}
		else
			return 0;
	}
	bool angle::operator >(const angle& gamma) {
		if ((this->degree - fault) > gamma.degree) {
			return 1;
		}
		else
			return 0;
	}
	bool angle::operator >(const double& gamma) {
		if ((this->degree - fault) > gamma)
			return 1;
		else
			return 0;
	}
	bool angle::operator <(const angle& gamma) {
		if ((this->degree + fault) < gamma.degree)
			return 1;
		else
			return 0;

	}
	bool angle::operator <(const double& gamma) {
		if ((this->degree + fault) < gamma)
			return 1;
		else
			return 0;

	}

	

	void typecheck(angle& a) {
		a.showValue();
		cout << "type = ";
		while (a > 360) {
			a.recount(a.degree - 360);
		}
		if (a > 90 && a < 180) cout << "\tobtuse \n\n\n";
		if (a < 90 && a>0) cout << "\tacute \n\n\n";
		if (a == 90) cout << "\trectangular\n\n\n";
		if (a == 180)cout << "\topen\n\n\n";
		if (a > 180 && a < 360)cout << "\tconvex \n\n\n";
		if (a == 360) cout << "\tfull \n\n\n";
	}
	angle::~angle() {
		cout << "Object  angle with (" << degree << "\t" << radian << ") sides deleted." << endl;
	}



