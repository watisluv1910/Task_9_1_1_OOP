#include "triangle_class.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {

	unsigned triangles_number = 0;
	cin >> triangles_number;

	vector<Triangle> triangles_list;

	for (unsigned i = 1; i <= triangles_number; i++)
	{
		int a_side = 0, b_side = 0, c_side = 0;
		cin >> a_side >> b_side >> c_side;

		Triangle temp_triangle(a_side, b_side, c_side);

		triangles_list.push_back(temp_triangle);
	}
	
	unsigned left_triangle_num = -1, right_triangle_num = -1;
	char operation_symbol = (char)32;

	while (cin >> left_triangle_num >> operation_symbol >> right_triangle_num)
	{
		Triangle temp_triangle = triangles_list.at(left_triangle_num - 1);

		if (operation_symbol == '+')
		{
			triangles_list.at(left_triangle_num - 1) 
				+= triangles_list.at(right_triangle_num - 1);
		}
		else if (operation_symbol == '-')
		{
			triangles_list.at(left_triangle_num - 1) 
				-= triangles_list.at(right_triangle_num - 1);
		}
		else
		{
			continue;
		}

		if (!triangles_list.at(left_triangle_num - 1).IsGoodTriangle())
		{
			triangles_list.at(left_triangle_num - 1) = temp_triangle;
		}
	}
	
	cout << "a = " << triangles_list.at(left_triangle_num - 1).get_sides().a_side
		<< "; b = " << triangles_list.at(left_triangle_num - 1).get_sides().b_side
		<< "; c = " << triangles_list.at(left_triangle_num - 1).get_sides().c_side
		<< ".";

	return 0;
}