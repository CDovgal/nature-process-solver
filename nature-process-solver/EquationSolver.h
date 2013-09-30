#pragma once

#include "AbstractBasis.h"

class DifferentialEquationSolver
{
public:
	DifferentialEquationSolver(FourierTransform* ip_transformation);

	virtual GridFunction* Solve(ContinuousFunction* ip_u);

	virtual ~DifferentialEquationSolver(){}

private:

	FourierTransform* mp_transformation;
};