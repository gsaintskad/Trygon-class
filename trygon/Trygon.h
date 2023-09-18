#pragma once
#include"angle.h"
#include<string>
using namespace std;
class Trygon
{

public:

	Trygon(double ina, double inb, double inc);
	Trygon(double ina, double inb, angle angGamma);
	Trygon(double ina, angle angAlfa, angle angBetta);
	Trygon();
	void recount(double ina, double inb, double inc);
	void recount(double ina, double inb, angle angGamma);
	void recount(double ina, angle angAlfa, angle angBetta);
	string getType();
	int getid();
	static int getcount() { return count; }
	Trygon& operator = (const Trygon* tr);
	~Trygon();
	void print();

private:

	string type;
	static int count;

	/*Статические поля для классов используются для передачи данных
	* между всеми объектами данного класса
	* к примеру можно зделать счетчик объектов или реализацию росставления
	* идентификаторов . Установление идентификаторов в классе Треугольник
	* реализовано при помощи функции void setid(). Чтобы идентификаторы
	* устанавливались автоматически их необходимо прописывать в каждой перегрузке
	* конструктора данного класса
	*/

	void setid() {

		id = count;
		count++;

	}
	int id;
	Trygon* adress = this;
	/*реализация указателя this
	* this - это указатель объекта на самого себя ,
	* в данном классе треугольник 	(Trygon* adress = this;)
	* поле adress будет хранить в себе адресс конкретно этого объекта
	*/
	
	double a;
	double b;
	double c;
	double S;
	double P;
	double hp;
	double r;
	double R;
	angle gamma;
	angle alfa;
	angle betta;



	void typecheck();
};

//статические переменные должны инициализироваться 
//вне класса , к которому пренадлежит статическая переменна 
//делается это образом показанным выше

