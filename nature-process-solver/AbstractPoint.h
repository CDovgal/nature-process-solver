#pragma once

class Point1D
{
public:
	explicit Point1D(double i_x)
		: m_x(i_x)
	{
	}

	//operator double(){ return m_x; }
	
	virtual double x() const { return m_x; }
	virtual double& rx() {return m_x; }
	
	
	virtual ~Point1D(){}

private:
	double m_x;
};

bool operator<(const Point1D& lhv, const Point1D& rhv)
{
	return lhv.x() < rhv.x();
}

bool operator==(const Point1D& lhv, const Point1D& rhv)
{
	return lhv.x() == rhv.x();
}

bool operator>(const Point1D& lhv, const Point1D& rhv)
{
	return lhv.x() > rhv.x();
}
