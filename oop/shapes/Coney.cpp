#include "Coney.h"
#include <math.h>
#include<iomanip>

Coney::Coney(float h, float r, float x, float y):Circle(r,x,y)
{
	height = h;
}

float Coney::getHeight()const {
	return height;
}

void Coney::setHeight(float h){
	height = h;
}

float Coney::area() const {
	return M_PI * radius * ( pow(radius,2) + pow(height,2) ) + Circle::area();
}

float Coney::volume() const {
	return ( height * Circle::area() )/3;
}

ostream& operator<< (ostream &output, const Coney& c){
	output<< "����� = [" << c.x << ", " << c.y << "]\n"
	<< "����� = " << c.radius << "\n������ = " << c.height;
	return output;
}

Coney::~Coney()
{
}
