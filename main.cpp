// AlgorithmAnalysisQ1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "AlgorithmProblem.h"
#include "AlgorithmSolver.h"

int main(int argc, char* argv[]) {
	if (argc < 4) {
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
	else if (argc == 4) {
		AlgorithmProblem _problem;
		AlgorithmSolver _algorithm;
		_problem.Load(argv[1], argv[2], atoi(argv[3]));
		_algorithm.RunSolver(_problem);
		_algorithm.OutputResult();
	}
	else {
		std::cout << "Too many arguments given!\n";
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
}
