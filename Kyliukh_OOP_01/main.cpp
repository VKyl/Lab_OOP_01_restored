#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 1), p2(1, 2), p3(2, 5);
	Triangle t(p, p2, p3);
	std::cout << t.medianAC() << std::endl;
	t.a(1, 3);
	std::cout << t.a() << std::endl;
	return 0;
}