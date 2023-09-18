#include<iostream>
#include<string>
#include<math.h>
#include<string>
#include <windows.h>
#include"angle.h"
#include "Trygon.h"
using namespace std;
#define pi 3.14159265358979323846



//статические переменные должны инициализироваться 
//вне класса , к которому пренадлежит статическая переменна 
//делается это образом показанным выше
int main() {
	/*Trygon MyTrygon;
	goto sp;
err:
	system("cls");
	cout << "\t\t\tInvalid input data\n\n";
sp:
	cout << "\n================================================\n"
		<< "What do you know about your trygon? \n\n"
		<< "\t 1.\tChoose '1' if you know 3 sides of trygon\n\n"
		<< "\t 2.\tChoose '2' if you know 2 sides of trygon and angle between them \n\n"
		<< "\t 3.\tChoose '3' if you know 1 side of trygon , an angle , against known side, and any another angle of trygon\n\n";
	int answer;
	cin >> answer;
	if (answer != 1 && answer != 2 && answer != 3)goto err;
	else if (answer == 1) {


		cout << "Enter sides of trygon you want : " << endl;
		double a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;


		MyTrygon.recount(a, b, c);
		MyTrygon.print();


	}
	else if (answer == 2) {
		cout << "Enter 2 sides of trygon you know , and angle between them : " << endl;
		double a, b, c;
		angle gamma;
		cout << "\tEnter first side : ";
		cin >> a;
		cout << "\nEnter second side : ";
		cin >> b;
		cout << "Enter angle between them in degrees :";

		cin >> c;


		gamma.recount(c);


		MyTrygon.recount(a, b, gamma);
	}
	else{
		cout << "Enter side of trygon you know , angle against him ,end another one : " << endl;
		double a, b, c;
		angle alfa,betta;
		cout << "\tEnter side : ";
		cin >> a;

		cout << "\n\n\n Enter angle against known side in degrees: \n\n";
		cin >> c;

		alfa.recount(c);


		cout << "\n\n\n Enter another angle in degrees : \n\n";
		cin >> b;

		betta.recount(b);


		MyTrygon.recount(a,alfa,betta);
	}

	MyTrygon.print();

	Trygon MyTrygon2;
	MyTrygon2 = MyTrygon;
	MyTrygon2.print();
	cout << &MyTrygon << endl << &MyTrygon2 << endl << endl << endl << endl << endl;
	cout << "sdas";*/
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


