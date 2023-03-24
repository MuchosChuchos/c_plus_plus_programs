#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle : public Point
{
	
	friend ostream &operator<< (ostream&, const Circle &);
	protected: 
		float radius;
	public:
		Circle(float r = 0.0, float x = 0.0, float y = 0.0);
		void setRadius(float);
		float getRadius()const;
		float area()const;
		~Circle();
};

#endif
