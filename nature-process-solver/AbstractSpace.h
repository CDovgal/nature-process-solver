#pragma once

#include "AbstractPoint.h"
#include "AbstractBound.h"

class GridSpace
{
public:
	GridSpace(const Bound1D& i_bound, double h);

	Bound1D GetBound() const;
	Point1D GetMin() const;
	Point1D GetMax() const;

	virtual ~GridSpace(){}
};