#pragma once

#include "AbstractPoint.h"

class Bound1D
{
public:
	Bound1D(const Point1D& i_min, const Point1D& i_max);

	Point1D GetMin() const;
	Point1D GetMin() const;

	virtual ~Bound1D(){}
};