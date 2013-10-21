#pragma once

#include "AbstractBasis.h"

class DifferentialEquationSolver
{
public:
	DifferentialEquationSolver(FourierTransform* ip_transformation)
		: mp_transformation(ip_transformation)
	{}

	virtual GridFunction* Solve(ContinuousFunction* ip_f)
	{
		return nullptr;
	}

	virtual ~DifferentialEquationSolver(){}
private:
	FourierTransform* mp_transformation;
};