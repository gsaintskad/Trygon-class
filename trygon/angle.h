#pragma once

#include<iostream>
#include<string>
#include<math.h>
#include<string>
#include <windows.h>
class angle
{

public:
	double radian;
	double degree;
	angle();
	angle(bool type, double value);
	angle(double value);
	void showValue();
	void recount(bool type, double value);
	void recount(double value);
	angle operator =(const angle& alfa);
	bool operator ==(const angle& gamma);
	bool operator ==(const double& gamma);
	bool operator >(const angle& gamma);
	bool operator >(const double& gamma);
	bool operator <(const angle& gamma);
	bool operator <(const double& gamma);
	
	friend void typecheck(angle& a);


	~angle();
private:

	float fault ;
};


