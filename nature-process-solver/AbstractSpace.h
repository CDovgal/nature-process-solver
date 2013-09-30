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
	GridSpace1D(const Bound1D& i_bound, double h)
		: m_bound(i_bound)
		, m_grid_size(h)
	{}

	virtual Bound1D GetBound() const { return m_bound; }
	virtual Point1D GetMin() const { return m_bound.GetMin(); }
	virtual Point1D GetMax() const { return m_bound.GetMax(); }
	virtual Distance GetSize() const { return m_bound.GetSize(); }

	double GetGridSize() const { return m_grid_size; }

	virtual ~GridSpace1D(){}

private:

	Bound1D m_bound;
	double m_grid_size;
};

class ContinuousSpace1D : public AbstractSpace1D
{
public:
	ContinuousSpace1D(const Bound1D& i_bound);

	virtual Bound1D GetBound() const { return m_bound; }
	virtual Point1D GetMin() const { return m_bound.GetMin(); }
	virtual Point1D GetMax() const { return m_bound.GetMax(); }

	virtual ~ContinuousSpace1D(){}

private:

	Bound1D m_bound;
};