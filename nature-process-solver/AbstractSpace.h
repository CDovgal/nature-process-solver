#pragma once

#include "AbstractPoint.h"
#include "AbstractBound.h"

class AbstractSpace1D
{
public:
	virtual Bound1D GetBound() const = 0;
	virtual Point1D GetMin() const = 0;
	virtual Point1D GetMax() const = 0;

	virtual ~AbstractSpace1D(){}

};

class GridSpace1D : public AbstractSpace1D
{
public:
	GridSpace1D(const Bound1D& i_bound, double h);

	virtual Bound1D GetBound() const;
	virtual Point1D GetMin() const;
	virtual Point1D GetMax() const;
	double GetGridSize() const;

	virtual ~GridSpace1D(){}
};

class ContinuousSpace1D : public AbstractSpace1D
{
public:
	ContinuousSpace1D(const Bound1D& i_bound);

	virtual Bound1D GetBound() const;
	virtual Point1D GetMin() const;
	virtual Point1D GetMax() const;

	virtual ~ContinuousSpace1D(){}
};