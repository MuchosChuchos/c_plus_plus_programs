#ifndef CONEY_H
#define CONEY_H

#include "circle.h"

class Coney : public Circle
{

	friend ostream &operator<< (ostream&, const Coney &);
	public:
		Coney(float h = 0.0, float r = 0.0, float x = 0.0, float y = 0.0);
		void setHeight(float);
		float getHeight()const;
		float area()const;
		float volume()const;
		~Coney();
	protected:
		float height;
};

#endif
