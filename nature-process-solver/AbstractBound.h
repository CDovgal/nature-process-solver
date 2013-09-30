#pragma once

#include "AbstractPoint.h"

typedef double Distance;

class Bound1D
{
public:
	Bound1D(const Point1D& i_min, const Point1D& i_max)
		: m_min(i_min)
		, m_max(i_max)
	{
		assert(GetMax() > GetMin());
	}

	Point1D GetMin() const { return m_min; };
	Point1D GetMax() const { return m_max; };

	Distance GetSize() const { return m_max() - m_min(); };

	virtual ~Bound1D(){}

private:
	Point1D m_min;
	Point1D m_max;
};