#pragma once

#include "AbstractPoint.h"
#include "AbstractSpace.h"

class AbstractFunction
{
public:
	virtual Point1D operator()(const Point1D& i_point) = 0;

	virtual ~AbstractFunction(){}
};

class GridFunction : public AbstractFunction
{
public:
	GridFunction(GridSpace1D* ip_space, std::function<double(double)>& i_function);

	virtual Point1D operator()(const Point1D& i_point);
	virtual Point1D operator()(size_t i_index);

	virtual ~GridFunction(){}

};

class ContinuousFunction : public AbstractFunction
{
public:
	ContinuousFunction(ContinuousSpace1D* ip_space, std::function<double(double)>& i_function);

	virtual Point1D operator()(const Point1D& i_point);

	virtual ~ContinuousFunction(){}

};