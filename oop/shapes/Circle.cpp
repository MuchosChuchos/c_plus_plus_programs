#include "Circle.h"
#include<math.h>
#include<iomanip>
Circle::Circle(float r, float a, float b): Point(a,b)
{
	radius = r;
}
void Circle::setRadius(float r)
{
	radius = r;
}
float Circle::getRadius()const
{
	return radius;
}
float Circle::area()const
{
	return (M_PI * radius * radius);
}

ostream &operator<< (ostream &output, const Circle &c)
{
	output << "����� = [ " << c.x << ", " << c.y << "];\n"<<"����� = " << c.radius;
	return output;
}

Circle::~Circle()
{
}
