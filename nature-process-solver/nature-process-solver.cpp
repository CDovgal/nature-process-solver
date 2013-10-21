// nature-process-solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

#include "EquationSolver.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{	

	GridSpace1D* space = new GridSpace1D( Bound1D( Point1D(0),Point1D(1) ), 0.1 );
	
	FourierBasis* basis = new FourierBasis(space);
	auto func = basis->gridFunction( 1 );

	return 0;
}

