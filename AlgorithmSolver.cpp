#include "AlgorithmSolver.h"

#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>

AlgorithmSolver::AlgorithmSolver() {

}

AlgorithmSolver::~AlgorithmSolver() {

}

int AlgorithmSolver::FindIndex(std::vector<int> _container, int _value){
	for (int i{0}; i < _container.size(); ++i)
		if (_container[i] == _value)
			return i;
	
	return -1;
}

bool AlgorithmSolver::CompareResidencyOverHospital(int _hospitalIndex, int _resident1, int _resident2){
	int resident1PrefIndex{	FindIndex(problem->Hospitals[_hospitalIndex], _resident1) },
		resident2PrefIndex{ FindIndex(problem->Hospitals[_hospitalIndex], _resident2)};

	if (resident1PrefIndex < resident2PrefIndex)
		return true;
	
	return false;
}

void AlgorithmSolver::RemoveValueFromList(std::vector<int> _container, int _value){
	//_container.erase(std::find(_container.begin(), _container.end(), _value));
}	

void AlgorithmSolver::RunSolver(AlgorithmProblem& _problem) {
	this->problem = &_problem;
	this->RunSolver();
}

void AlgorithmSolver::RunSolver() {
	while (problem->FreeResidents.size() > 0){
		int residentIndex{problem->FreeResidents.front()};
		bool matchFlag{false};
		while(problem->Residents[residentIndex].size() != 0 && matchFlag == false){
			int prefHospitalIndex{problem->Residents[residentIndex].front()};
			problem->Residents[residentIndex].erase(problem->Residents[residentIndex].begin());
			if (problem->HospitalCapacity[prefHospitalIndex].size() < problem->maxCapacity){
				problem->HospitalCapacity[prefHospitalIndex].emplace_back(residentIndex);
				problem->FreeResidents.erase(problem->FreeResidents.begin());
				matchFlag = true;
			}
			else{
				for (int j{0}; j < problem->Hospitals[prefHospitalIndex].size(); ++j){
					int competingResidentIndex{problem->Hospitals[prefHospitalIndex][j]};
					if (CompareResidencyOverHospital(prefHospitalIndex, residentIndex, competingResidentIndex)){
						// Remove
						problem->HospitalCapacity[prefHospitalIndex].erase(std::find(problem->HospitalCapacity[prefHospitalIndex].begin(), problem->HospitalCapacity[prefHospitalIndex].end(), competingResidentIndex));
						problem->HospitalCapacity[prefHospitalIndex].emplace_back(residentIndex);
						problem->FreeResidents.erase(problem->FreeResidents.begin());
						problem->FreeResidents.emplace_back(competingResidentIndex);						
						matchFlag = true;
						break;
					}
					else{
						// Do nothing
					}
				}
			}
		}
	}

	for (int hospitalIndex{0}; hospitalIndex < problem->HospitalCapacity.size(); ++hospitalIndex){
		MatchResults.emplace_back(std::vector<int>{});
		for (int i{0}; i < problem->HospitalCapacity[hospitalIndex].size(); ++i)
			MatchResults[hospitalIndex].emplace_back(problem->HospitalCapacity[hospitalIndex][i]);
	}	
}

std::string to_format(const int number) {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}

void AlgorithmSolver::OutputResult(){
	for (int i{0}; i < MatchResults.size(); ++i){
		for (int j{0}; j < MatchResults[i].size(); ++j){
			if (j != MatchResults[i].size() - 1)
				std::cout << to_format(MatchResults[i][j]) << " ";
			else
				std::cout << to_format(MatchResults[i][j]) << std::endl;
		}
	}
}
