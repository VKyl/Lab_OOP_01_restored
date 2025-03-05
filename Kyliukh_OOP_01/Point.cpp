#include "Point.h"

Point::Point(double x, double y): _x(x), _y(y) {}

Point::Point(const Point& p): _x(p.x()), _y(p.y()) {
#ifndef NDEBUG
	std::cout << "copied!" << std::endl;
#endif 

}

Point& Point::operator+=(const Point& v)
{
	x() += v.x();
	y() += v.y();
	return *this;
}

Point& Point::operator-=(const Point& v)
{
	x() -= v.x();
	y() -= v.y();
	return *this;
}

Point& Point::operator=(const Point& p)
{
	x() = p.x();
	y() = p.y();
	return *this;
}

ostream& operator<< (ostream& out, const Point& p)
{
	out << p.x() << ' ' << p.y();
	return out;
}

_NODISCARD const Point operator+ (const Point& u, const Point& v)
{
	return { u.x() + v.x(), u.y() + v.y()};
}

_NODISCARD const Point operator- (const Point& u, const Point& v)
{
	return { u.x() - v.x(), u.y() - v.y() };
}

bool operator==(const Point& u, const Point& v)
{
	return (fabs(u.x() - v.x()) <= DBL_EPSILON) && (fabs(u.y() - v.y()) <= DBL_EPSILON);
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}

bool isSharingLine(const Point& a, const Point& b, const Point& c)
{
	return fabs((b.y() - a.y()) * (c.x() - a.x()) - (c.y() - a.y()) * (b.x() - a.x())) <= DBL_EPSILON;
}