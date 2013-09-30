#pragma once

#include "AbstractSpace.h"
#include "AbstractFunction.h"

class FourierBasis
{
public:
	FourierBasis(GridSpace1D* ip_space);

	virtual double GetEigenValue(size_t i_index);
	virtual GridFunction* GetEigenFunction(size_t i_index);

	virtual ~FourierBasis(){}
};

class FourierTransform
{
public:
	FourierTransform(FourierBasis* ip_basis);

	GridFunction* GetTransform(ContinuousFunction* ip_function);

	virtual ~FourierTransform();
};