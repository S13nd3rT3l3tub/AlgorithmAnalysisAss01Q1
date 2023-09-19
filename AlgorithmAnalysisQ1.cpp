// AlgorithmAnalysisQ1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "AlgorithmSolver.h"

int main(int argc, char* argv[]) {
	if (argc < 4) {
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
	else if (argc == 4) {
		<Problem data type> _problem{ argv[1], argv[2], argv[3] };
		AlgorithmSolver _solver{ };
		_solver.RunSolver(_problem);
	}
	else {
		std::cout << "Too many arguments given!\n";
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
}