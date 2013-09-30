#pragma once

class Point1D
{
public:
	explicit Point1D(double i_x);

	virtual double operator()();
	virtual double operator()() const;

	virtual ~Point1D(){}
};
