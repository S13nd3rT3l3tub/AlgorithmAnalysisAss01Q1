#include "AlgorithmSolver.h"

#include <string>

AlgorithmSolver::AlgorithmSolver() {

}

AlgorithmSolver::~AlgorithmSolver() {

}

void AlgorithmSolver::RunSolver(<Problem data type> _problem) {
	for (int hospitalIndex{ 0 }; hospitalIndex < _problem.hospitalcapacity.size(); ++hospitalIndex) {
		for (int i{ _problem.hospitalcapacity[hospitalIndex].size() }; i < _problem.capacity; i = _problem.hospitalcapacity[hospitalIndex].size()) {

		}
	}
}


//if (argc < 4) {
//	std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
//}
//else if (argc == 4) {
//	<Problem data type> _problem{ argv[1], argv[2], argv[3] };
//	AlgorithmSolver _solver{ };
//	_solver.RunSolver(_problem);
//}
//else {
//	std::cout << "Too many arguments given!\n";
//	std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
//}