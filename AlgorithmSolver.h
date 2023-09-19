#ifndef ALGORITHMSOLVER
#define ALGORITHMSOLVER

#include <vector>

#include "AlgorithmProblem.h"

class AlgorithmSolver {
private:
	std::vector<std::vector<int>> MatchResults;

	AlgorithmProblem* problem;
	int FindIndex(std::vector<int> _container, int _value);
	void RemoveValueFromList(std::vector<int> _container, int _value);
	bool CompareResidencyOverHospital(int _hospital, int _resident1, int _resident2);
public:
	AlgorithmSolver();
	~AlgorithmSolver();
	void RunSolver(AlgorithmProblem& _problem);
	void RunSolver();

	void OutputResult();
};

#endif