#ifndef ALGORITHMSOLVER
#define ALGORITHMSOLVER

#include <vector>
#include <unordered_map>

#include "AlgorithmProblem.h"

class AlgorithmSolver {
private:
	AlgorithmProblem* problem;
	int FindIndex(std::vector<int> _container, int _value);
    bool ContainerHasValue(std::vector<int> _container, int _value);
	void RemoveValueFromList(std::vector<int>& _container, int _value);
	bool CompareResidencyOverHospital(int _hospital, int _resident1, int _resident2);
    int FindLeastPreferredCandidate(int hospital);
public:
	AlgorithmSolver();
	~AlgorithmSolver();
	void RunSolver(AlgorithmProblem& _problem);
	void RunSolver();

	void OutputResult();
};

#endif