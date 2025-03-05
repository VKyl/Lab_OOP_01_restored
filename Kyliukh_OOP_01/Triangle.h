#pragma once
#include "Point.h"
#include <cassert>
#include <cmath>

class Triangle
{
public:
	class Segment
	{
	private:
		const Point& _a;
		const Point& _b;

	public:
		Segment(const Point& a, const Point& b);

		const double length();

		const Point& a() const;
		const Point& b() const;
	};

private:
	Point _a, _b, _c;
	Segment *_ab_ptr = nullptr, 
		    * _ac_ptr = nullptr, 
		    * _bc_ptr = nullptr;
	
	Segment* _ab_m_ptr = nullptr,
		* _ac_m_ptr = nullptr,
		* _bc_m_ptr = nullptr;

	Point *_ab_m_p_ptr = nullptr, 
		  *_ac_m_p_ptr = nullptr, 
		  *_bc_m_p_ptr = nullptr;

public:
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);

	Triangle(const Point& a, const Point& b, const Point& c);

	Triangle(const Triangle& t);

	Triangle(Triangle&& t) noexcept;

	~Triangle();

	const Point& a() const;
	void a(const double x, const double y);
	void a(const Point& p);

	const Point& b() const;
	void b(const double x, const double y);
	void b(const Point& p);

	const Point& c() const;
	void c(const double x, const double y);
	void c(const Point& p);

	const Segment& ab();
	const Segment& ac();
	const Segment& bc();

	const Point& mPointAB();
	const Point& mPointAC();
	const Point& mPointBC();

	const Segment& medianAB();
	const Segment& medianAC();
	const Segment& medianBC();

	Triangle& operator=(const Triangle& t);
	Triangle& operator=(Triangle&& t) noexcept; 

private:
	
	void clearTriangle(Triangle& t);
	void clearSideRelatedPtrs(Point* m_p_ptr, Segment* m_ptr);
	
	void reCalcMidPoint(Point* m_p_ptr, const Point& p1, const Point& p2);
	const Point& getMidPointOrCalc(Point* m_p_ptr, const Point& p1, const Point& p2);
	const Segment& getSegmentOrCalc(Segment* segment_ptr, const Point& p1, const Point& p2);
};

ostream& operator<<(ostream& out, const Triangle& t);
ostream& operator<<(ostream& out, const Triangle::Segment& s);

template <typename T>
void clearPtr(T* segment_ptr)
{
	delete segment_ptr;
	segment_ptr = nullptr;
}