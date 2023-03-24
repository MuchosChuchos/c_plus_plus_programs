#include "Point.h"

Point::Point(float _x, float _y) {
	x = _x;
	y = _y;
}

float Point::getX() const { return x; }
float Point::getY() const { return y; }

void Point::setX(float _x) { x = _x; }
void Point::setY(float _y) { y = _y; }

ostream &operator<< (ostream &output, const Point &p)
{
	output << "[ " << p.x << ", " << p.y << "]";
	return output;
}
