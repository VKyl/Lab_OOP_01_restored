#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 1), p2(1, 2), p3(2, 2);
	Triangle t(p, p2, p3);
	std::cout << t;
	return 0;
}