#pragma once

class Point1D
{
public:
	explicit Point1D(double i_x);

	//operator double(){ return m_x; }
	
	virtual double& operator()() { return m_x; }
	virtual const double& operator()() const { return m_x; }
	
	virtual ~Point1D(){}

private:
	double m_x;
};

bool operator<(const Point1D& lhv, const Point1D& rhv)
{
	return lhv() < rhv();
}
bool operator==(const Point1D& lhv, const Point1D& rhv)
{
	return lhv() == rhv();
}
bool operator>(const Point1D& lhv, const Point1D& rhv)
{
	return lhv() > rhv();
}
