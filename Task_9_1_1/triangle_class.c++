#include "triangle_class.h"

Triangle& operator+=(Triangle& left_triangle, const Triangle& right_triangle)
{
	left_triangle.triangle_sides.a_side += right_triangle.triangle_sides.a_side;
	left_triangle.triangle_sides.b_side += right_triangle.triangle_sides.b_side;
	left_triangle.triangle_sides.c_side += right_triangle.triangle_sides.c_side;

	return left_triangle;
}

Triangle& operator-=(Triangle& left_triangle, const Triangle& right_triangle)
{
	left_triangle.triangle_sides.a_side -= right_triangle.triangle_sides.a_side;
	left_triangle.triangle_sides.b_side -= right_triangle.triangle_sides.b_side;
	left_triangle.triangle_sides.c_side -= right_triangle.triangle_sides.c_side;

	return left_triangle;
}

bool Triangle::IsGoodTriangle()
{
	if (triangle_sides.a_side + triangle_sides.b_side <= triangle_sides.c_side 
		|| triangle_sides.a_side + triangle_sides.c_side <= triangle_sides.b_side 
		|| triangle_sides.b_side + triangle_sides.c_side <= triangle_sides.a_side)
	{
		return false;
	}
	else if (triangle_sides.a_side <= 0 
		|| triangle_sides.b_side <= 0 
		|| triangle_sides.c_side <= 0)
	{
		return false;
	}

	return true;
}

sides Triangle::get_sides()
{
	return triangle_sides;
}