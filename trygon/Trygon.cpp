#include"Trygon.h"
#include"angle.h"
#include<iostream>
#include<string>
#include<math.h>
#include<string>
#include <windows.h>


#define pi 3.14159265358979323846

using namespace std;

Trygon::Trygon(double ina, double inb, double inc) {
	this->setid();
	this->a = ina;
	this->b = inb;
	this->c = inc;
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->gamma.recount(0, acos((a * a + b * b - c * c) / (2 * a * b)));
	this->alfa.recount(0, acos((c * c + b * b - a * a) / (2 * c * b)));
	this->betta.recount(0, acos((c * c + a * a - b * b) / (2 * c * a)));
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();
}
Trygon::Trygon(double ina, double inb, angle angGamma) {
	this->setid();
	this->a = ina;
	this->b = inb;
	this->gamma = angGamma;
	this->c = sqrt(a * a + b * b - 2 * a * b * cos(gamma.radian));
	this->alfa.recount(0, acos((c * c + b * b - a * a) / (2 * c * b)));
	this->betta.recount(0, acos((c * c + a * a - b * b) / (2 * c * a)));
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();
}
Trygon::Trygon(double ina, angle angAlfa, angle angBetta) {
	this->setid();
	this->a = ina;
	this->alfa = angAlfa;
	this->betta = angBetta;
	this->gamma.recount(180.0 - alfa.degree - betta.degree);
	this->b = a * sin(betta.radian) / sin(alfa.radian);
	this->c = a * sin(gamma.radian) / sin(alfa.radian);
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();

}
Trygon::Trygon() {
	this->setid();
	this->type = "equilateral";
	this->a = 1;
	this->b = 1;
	this->c = 1;
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->gamma = acos((a * a + b * b - c * c) / (2 * a * b)) / pi * 180;
	this->alfa = acos((c * c + b * b - a * a) / (2 * c * b)) / pi * 180;
	this->betta = acos((c * c + a * a - b * b) / (2 * c * a)) / pi * 180;
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
}
void Trygon::recount(double ina, double inb, double inc) {
	this->a = ina;
	this->b = inb;
	this->c = inc;
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->gamma.recount(0, acos((a * a + b * b - c * c) / (2 * a * b)));
	this->alfa.recount(0, acos((c * c + b * b - a * a) / (2 * c * b)));
	this->betta.recount(0, acos((c * c + a * a - b * b) / (2 * c * a)));
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();
}
void Trygon::recount(double ina, double inb, angle angGamma) {
	this->a = ina;
	this->b = inb;
	this->gamma = angGamma;
	this->c = sqrt(a * a + b * b - 2 * a * b * cos(gamma.radian));
	this->alfa.recount(0, acos((c * c + b * b - a * a) / (2 * c * b)));
	this->betta.recount(0, acos((c * c + a * a - b * b) / (2 * c * a)));
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();
}
void Trygon::recount(double ina, angle angAlfa, angle angBetta) {

	this->a = ina;
	this->alfa = angAlfa;
	this->betta = angBetta;
	this->gamma.recount(180.0 - alfa.degree - betta.degree);
	this->b = a * sin(betta.radian) / sin(alfa.radian);
	this->c = a * sin(gamma.radian) / sin(alfa.radian);
	this->hp = (a + b + c) / 2;
	this->S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));
	this->P = hp * 2;
	this->r = S / hp;
	this->R = (a * b * c) / (4 * S);
	this->typecheck();

}
string Trygon::getType() { return this->type; }

int Trygon::getid() { return id; }

Trygon& Trygon::operator = (const Trygon* tr) {
	cout << "Trygon a with type :" << tr->type << "with adress : " << "was coppied to adress : " << this << ":) " << endl;
	this->a = tr->a;
	this->b = tr->b;
	this->c = tr->c;
	this->alfa = tr->alfa;
	this->betta = tr->betta;
	this->gamma = tr->gamma;
	this->S = tr->S;
	this->P = tr->P;
	this->hp = tr->hp;
	this->r = tr->r;
	this->R = tr->R;
	return *this;
}

Trygon::~Trygon() {
	cout << "Object " << type << " trygon with(" << a << ", " << b << ", " << c << ") sides deleted." << endl;
}
void Trygon::print() {
	cout << "\n================================================\n";
	cout << "\n\nSIDES OF TRYGON number " << id << endl << endl
		<< "\ta\t " << a << endl
		<< "\tb\t " << b << endl
		<< "\tc\t " << c << endl
		<< "\n\n"
		<< "TYPE OF TRYGON :\t" << type
		<< "\n\n"
		<< "AREA OF TRYGON :\t " << S << endl
		<< "PERIMETR OF TRYGON :\t " << P << endl;
	cout << "\n\n\nANGLES\t:\n\n";
	cout << "\t<(a,b) =\t" << "in degrees : \t" << gamma.degree << "\t\t in radians : \t" << gamma.radian << "\n";
	cout << "\t<(b,c) =\t" << "in degrees : \t" << alfa.degree << "\t\t in radians : \t" << alfa.radian << "\n";
	cout << "\t<(a,c) =\t" << "in degrees : \t" << betta.degree << "\t\t in radians : \t" << betta.radian << "\n\n\n\n";
	cout << "RADIUSES :"
		<< "\n\n\tInscribed circle radius\t:\t" << r << "\n\tCircumscribed radius circle\t:\t" << R;
	cout << "\n\n\n\n\n";
	cout << "\n================================================\n";
}



	int Trygon::count=0;
//статические переменные должны инициализироваться 
//вне класса , к которому пренадлежит статическая переменна 
//делается это образом показанным выше


	/*Статические поля для классов используются для передачи данных
	* между всеми объектами данного класса
	* к примеру можно зделать счетчик объектов или реализацию росставления
	* идентификаторов . Установление идентификаторов в классе Треугольник
	* реализовано при помощи функции void setid(). Чтобы идентификаторы
	* устанавливались автоматически их необходимо прописывать в каждой перегрузке
	* конструктора данного класса
	*/

	
	
	/*реализация указателя this
	* this - это указатель объекта на самого себя ,
	* в данном классе треугольник 	(Trygon* adress = this;)
	* поле adress будет хранить в себе адресс конкретно этого объекта
	*/
	


	void Trygon::typecheck() {
		angle s[3] = { alfa,betta,gamma };
		angle c;
		for (int i = 0; i < 3; i++) {
			if (c.degree < s[i].degree) c = s[i];
		}
		if (c > 90)type = " obtuse ";
		if (c < 90)type = " acute ";
		if (c == 90) type = " rectangular";
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) type = " isosceles " + type;
		if (s[1] == s[0] && s[0] == s[2]) {
			type = " equilateral ";
		}

	}




