#pragma once

#include "AbstractPoint.h"
#include "AbstractSpace.h"

class AbstractFunction
{
public:
	virtual double operator() (const Point1D& i_point) = 0;

	virtual ~AbstractFunction(){}
};

class GridFunction : public AbstractFunction
{
public:
	GridFunction(GridSpace1D* ip_space, const std::vector<double>& i_values)
		: mp_space(ip_space)
		, m_values(i_values)
	{}
	//GridFunction(GridSpace1D* ip_space, std::function<double(double)>& i_function);
	
	virtual double operator() (const Point1D& i_point)
	{
		return 0;//m_values[i_index];
	}

	virtual double operator() (size_t i_index)
	{
		return 0;//
	}

	virtual ~GridFunction(){}
private:
	GridSpace1D* mp_space;
	std::vector<double> m_values;
};

class ContinuousFunction : public AbstractFunction
{
public:
	ContinuousFunction(ContinuousSpace1D* ip_space, std::function<double(const Point1D&)>& i_function)
		: mp_space(ip_space)
		, m_function(i_function)
	{
		
	}

	virtual double operator() (const Point1D& i_point);

	virtual ~ContinuousFunction(){}
private:
	ContinuousSpace1D* mp_space;
	std::function<double(const Point1D&)> m_function;
};