#include <iostream>
#include "Triangle.h"

int main()
{
	Point p(1, 1), p2(1, 2), p3(2, 5);
	Triangle t(p, p2, p3);
	std::cout << "Median on AB " << t.medianAB() << std::endl;
	std::cout << "Median on BC " << t.medianBC() << std::endl;
	std::cout << "Median on AC " << t.medianAC() << std::endl;
	t = { {1,3}, {2, 3}, {4, 5} };
	std::cout << "Median on AB " << t.medianAB() << std::endl;
	std::cout << "Median on BC " << t.medianBC() << std::endl;
	std::cout << "Median on AC " << t.medianAC() << std::endl;
	return 0;
}