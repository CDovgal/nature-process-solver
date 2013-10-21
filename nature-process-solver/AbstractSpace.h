#pragma once

#include "AbstractPoint.h"
#include "AbstractBound.h"

class AbstractSpace1D
{
public:
	virtual Bound1D getBound() const = 0;

	virtual ~AbstractSpace1D(){}
};

class GridSpace1D : public AbstractSpace1D
{
public:
	GridSpace1D(const Bound1D& i_bound, double h)
		: m_bound(i_bound)
		, m_grid_number(static_cast<size_t>(i_bound.GetSize() / h))
		, m_grid_size(h)
	{}

	virtual Bound1D getBound() const { return m_bound; }
	size_t getGridNumber() const {return m_grid_number; }
	double getGridSize() const { return m_grid_size; }

	virtual ~GridSpace1D(){}

private:
	Bound1D m_bound;
	size_t m_grid_number;
	double m_grid_size;
};

class ContinuousSpace1D : public AbstractSpace1D
{
public:
	ContinuousSpace1D(const Bound1D& i_bound);

	virtual Bound1D getBound() const { return m_bound; }

	virtual ~ContinuousSpace1D(){}

private:
	Bound1D m_bound;
};