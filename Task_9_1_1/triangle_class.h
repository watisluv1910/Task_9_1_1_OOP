#ifndef TRIANGLE_CLASS_H
#define TRIANGLE_CLASS_H

#include "sides_struct.h"

class Triangle
{
private:

	sides triangle_sides;
public:

	Triangle(int i, int j, int  k) { triangle_sides.a_side = i; triangle_sides.b_side = j; triangle_sides.c_side = k; }

	bool IsGoodTriangle();

	sides get_sides();

	friend Triangle& operator+= 
		(Triangle& left_value, const Triangle& right_value);

	friend Triangle& operator-= 
		(Triangle& left_value, const Triangle& right_value);
};

#endif