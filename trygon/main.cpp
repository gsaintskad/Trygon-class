#include<iostream>
#include<string>
#include<math.h>
#include<string>
#include <windows.h>
#include"angle.h"
#include "Trygon.h"
using namespace std;




int main() {
	angle b(5);
	angle c(5.000004);
	angle a(750);
	bool check;
	check = b == c;
	Trygon tryg(3, 4, 5);
	typecheck(a);
	tryg.print();
	Trygon t1(3, 4, 4);
	t1.print();
	cout << "!!!!!!!!!!" << t1.getid() << endl;
	return 0;
}


