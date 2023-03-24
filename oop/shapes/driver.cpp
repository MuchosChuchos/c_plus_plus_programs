#include"point.h"
#include"circle.h"
#include"coney.h"


#include<Windows.h>
#include<iomanip>


int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	Point point(9.3, 3.6), p;
	Circle circle(1.7, 1.2, 12.5), cir;
	Coney coney(15.1, 6.5, 9.3, 4.7), con;
	
	cout<< "Конструктори за замовчуванням для:\n" << "точки - " << p << "\nкола - " << cir << "\nконуса - " << con <<endl<<endl;	
	cout<< "Конструктори з параметрами для:\n" << "точки - " << point << "\nкола - " << circle << "\nконуса - " << coney <<endl<<endl;	

	
	con.setX(11.1);
	con.setY(11.1);
	con.setHeight(11.1);
	con.setRadius(11.1);
	
	cout<< "Конус: " << con << "\nйого площа = " << con.area() << "\nйого об'єм = " << con.volume() <<endl<<endl;
	
	
	circle.setX(22.2);
	circle.setY(22.2);
	circle.setRadius(22.2);
	
	cout<< "Коло: " << circle << "\nйого площа = " << circle.area() <<endl<<endl;
	
	
	point.setX(9.9);
	point.setY(10.9);
	
	cout<< "Точка: " << point <<endl<<endl;
	
	return 0;
}
