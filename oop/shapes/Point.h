#ifndef POINT_H
#define POINT_H

#include<iostream>
using namespace std;
class Point {
	
	friend ostream &operator<< (ostream&, const Point &);
	protected:
	   float x, y;  
	
	public:
	   Point(float x = 0, float y = 0);
	   float getX() const;  
	   void setX(float);  
	   float getY() const;
	   void setY(float);
};

#endif
