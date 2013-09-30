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
	GridFunction(GridSpace* ip_space, std::function<double(double)>& i_function);

	virtual Point1D operator()(const Point1D& i_point);

	virtual ~GridFunction(){}

};