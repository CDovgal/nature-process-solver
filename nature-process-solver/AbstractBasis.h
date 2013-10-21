#pragma once

#include "AbstractSpace.h"
#include "AbstractFunction.h"

class FourierBasis
{
public:
	FourierBasis(GridSpace1D* ip_space)
		: mp_space(ip_space)
	{
		init();
	}

	virtual double eigenValue(size_t i_index)
	{
		assert(i_index < m_eigenvalues.size());
		assert(i_index != 0);
		return m_eigenvalues[i_index];
	}

	virtual std::function<double (size_t)> gridFunction( size_t k )
	{
		auto l = mp_space->getBound().GetSize();
		auto koeff = sqrt(2./l);
		return [=] ( double x_i )
		{
			assert( k != 0 );
			return koeff*sin( (M_PI*k*x_i) / l);
		};
	}

	virtual std::function<double (size_t)> eigenVector( size_t i_k)
	{
		auto N = mp_space->getGridNumber();
		return [=] (size_t j)
		{
			return sin( M_PI*i_k*j / N);
		};
	}

	virtual ~FourierBasis(){}
private:
	void init()
	{
		generate_eigenvalues();
	}

	void generate_eigenvalues()
	{
		m_eigenvalues.resize( mp_space->getGridNumber() );

		auto l = mp_space->getBound().GetSize();
		auto h = mp_space->getGridSize();
		auto koeff = 4. / pow(h, 2);

		for(size_t k = 0; k < m_eigenvalues.size(); ++k)
			m_eigenvalues[k] = koeff * pow( sin( M_PI*k*h/(2*l) ), 2 );
	}

	GridSpace1D* mp_space;
	std::vector<double> m_eigenvalues;
};

class FourierTransform
{
public:
	FourierTransform(FourierBasis* ip_basis);

	GridFunction* getTransform(ContinuousFunction* ip_function);

	virtual ~FourierTransform();
};