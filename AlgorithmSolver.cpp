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
	for (int i{0}; i < static_cast<int>(_container.size()); ++i)
		if (_container[i] == _value)
			return i;
	return -1;
}

bool AlgorithmSolver::ContainerHasValue(std::vector<int> _container, int _value){
    if (std::find(_container.begin(), _container.end(), _value) != _container.end())
        return true;
    return false;
}

bool AlgorithmSolver::CompareResidencyOverHospital(int _hospitalIndex, int _resident1, int _resident2){
	int resident1PrefIndex{	FindIndex(problem->Hospitals[_hospitalIndex], _resident1) },
		resident2PrefIndex{ FindIndex(problem->Hospitals[_hospitalIndex], _resident2)};

	if (resident1PrefIndex < resident2PrefIndex)
		return true;
	return false;
}

void AlgorithmSolver::RemoveValueFromList(std::vector<int>& _container, int _value){
	_container.erase(std::find(_container.begin(), _container.end(), _value));
}	

void AlgorithmSolver::RunSolver(AlgorithmProblem& _problem) {
	this->problem = &_problem;
	this->RunSolver();
}

int AlgorithmSolver::FindLeastPreferredCandidate(int hospital) {
    // get the preferences
    auto pref_vect = problem->Hospitals[hospital];
    // get the current candidates BEFORE REPLACING
    auto curr_cand_vect = problem->HospitalCapacity[hospital];

    std::cout << "at hospital " << hospital << " there are ";
    for(int i = 0; i <curr_cand_vect.size(); i++ ) 
    {
        std::cout << curr_cand_vect[i] << " ";
    }
    std::cout << std::endl;

    int idx_to_replace = -1;
    int candidate_to_replace;

    for(int i = 0; i < curr_cand_vect.size(); ++i)
    {
        int shortlisted = curr_cand_vect[i];
        for(int j = 0; j< pref_vect.size(); ++j)
        {
            if(pref_vect[j] == shortlisted)
            {
                if(j > idx_to_replace)
                {
                    idx_to_replace = j;
                    candidate_to_replace = pref_vect[j];
                }
                break;
            }
        }
    }
    return candidate_to_replace;
}

void AlgorithmSolver::RunSolver() {
    // while there are still candidates still applying for residency
    while(problem->FreeResidents.size() != 0) { //n
		std::cout << problem->FreeResidents.size() << "	residencies remain.\n";
    	int residency{ problem->FreeResidents.front()};
    	bool matchFlag{ false };
    	std::cout << "Checking for " << residency << " residency";	
		while(problem->Residents[residency].size() != 0 && !matchFlag) {    //m
			int preferableHospital{ problem->Residents[residency].front()};
            std::cout << " at hospital " << preferableHospital << std::endl;
			RemoveValueFromList(problem->Residents[residency],preferableHospital);  // m
            if((static_cast<int>(problem->HospitalCapacity[preferableHospital].size()) < problem->maxCapacity )) {
				std::cout << "Added resident " <<  residency << " to hospital " << preferableHospital  << std::endl; 
                // add residency
				problem->HospitalCapacity[preferableHospital].emplace_back(residency);  // n
				RemoveValueFromList(problem->FreeResidents,residency); 
				matchFlag = true;
			}
            else {
                int candidate_to_replace = FindLeastPreferredCandidate(preferableHospital); // p c
                if(CompareResidencyOverHospital(preferableHospital,residency,candidate_to_replace)) {   // p
						// change operation
                        std::cout << residency << " will Replace " << candidate_to_replace << "\n";
						RemoveValueFromList(problem->HospitalCapacity[preferableHospital],candidate_to_replace);
						problem->HospitalCapacity[preferableHospital].emplace_back(residency);
						RemoveValueFromList(problem->FreeResidents,residency);  //n
						problem->FreeResidents.emplace_back(candidate_to_replace);
						matchFlag = true;
						// win
						break;
					}
                    else {
                        std::cout << residency << " Lost\n";
					}
			}
		}
        if (problem->Residents[residency].size() == 0 && !matchFlag)
            RemoveValueFromList(problem->FreeResidents,residency);  // n
    }
}
    

std::string to_format(const int number) {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}

void AlgorithmSolver::OutputResult() {
    for (auto it{problem->HospitalCapacity.begin()}; it != problem->HospitalCapacity.end(); ++it){
        std::cout << "Hospital " << it->first <<  " ------- Residences:"; 
        for (int j{0}; j < static_cast<int>(it->second.size()); ++j){
			if (j != (static_cast<int>(it->second.size()) - 1))
				std::cout << to_format(it->second[j]) << " ";
			else
				std::cout << to_format(it->second[j]) << std::endl;
		}
    }
}
