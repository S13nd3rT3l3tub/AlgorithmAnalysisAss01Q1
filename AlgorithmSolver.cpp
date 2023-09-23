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

int AlgorithmSolver::FindLeastPreferredCandidate(int hospital)
{
    // get the preferences
    auto pref_vect = problem->Hospitals[hospital];
    // get the current candidates BEFORE REPLACING
    auto curr_cand_vect = problem->HospitalCapacity[hospital];

    int to_replace = -1;

    for(int i = 0; i < curr_cand_vect.size(); ++i)
    {
        int candidate = curr_cand_vect[i];
        for(int j = 0; j< pref_vect.size(); ++j)
        {
            if(pref_vect[j] == candidate)
            {
                if(j > to_replace)
                {
                    to_replace = candidate;
                }
            }
        }
    }
    return to_replace;
}

void AlgorithmSolver::RunSolver() {
	// while (problem->FreeResidents.size() > 0){
	// 	int residentIndex{problem->FreeResidents.front()};
	// 	bool matchFlag{false};
	// 	while(problem->Residents[residentIndex].size() != 0 && matchFlag == false){
	// 		int prefHospitalIndex{problem->Residents[residentIndex].front()};
	// 		problem->Residents[residentIndex].erase(problem->Residents[residentIndex].begin());
	// 		if (problem->HospitalCapacity[prefHospitalIndex].size() < problem->maxCapacity){
	// 			problem->HospitalCapacity[prefHospitalIndex].emplace_back(residentIndex);
	// 			problem->FreeResidents.erase(problem->FreeResidents.begin());
	// 			matchFlag = true;
	// 		}
	// 		else{
	// 			for (int j{0}; j < problem->Hospitals[prefHospitalIndex].size(); ++j){
	// 				int competingResidentIndex{problem->Hospitals[prefHospitalIndex][j]};
	// 				if (CompareResidencyOverHospital(prefHospitalIndex, residentIndex, competingResidentIndex)){
	// 					// Remove
	// 					problem->HospitalCapacity[prefHospitalIndex].erase(std::find(problem->HospitalCapacity[prefHospitalIndex].begin(), problem->HospitalCapacity[prefHospitalIndex].end(), competingResidentIndex));
	// 					problem->HospitalCapacity[prefHospitalIndex].emplace_back(residentIndex);
	// 					problem->FreeResidents.erase(problem->FreeResidents.begin());
	// 					problem->FreeResidents.emplace_back(competingResidentIndex);						
	// 					matchFlag = true;
	// 					break;
	// 				}
	// 				else{
	// 					// Do nothing
	// 				}
	// 			}
	// 		}
	// 	}
	// }

    // while there are still candidates still applying for residency
    while(problem->FreeResidents.size() != 0)
    {
		std::cout << problem->FreeResidents.size() << "	residencies remain.\n";
	
    	int residency{ problem->FreeResidents.front()};
	
    	std::cout << "Checking for " << residency << " residency";
	
    	bool matchFlag{ false };


		while(problem->Residents[residency].size() != 0 && !matchFlag)
        {
			int preferableHospital{ problem->Residents[residency].front()};
            std::cout << " at hospital " << preferableHospital << std::endl;
			RemoveValueFromList(problem->Residents[residency],preferableHospital);
            
            if((problem->HospitalCapacity[preferableHospital].size() < problem->maxCapacity ))
            {
				std::cout << "Added resident " <<  residency << " to hospital " << preferableHospital  << std::endl; 
                // add residency
				problem->HospitalCapacity[preferableHospital].emplace_back(residency);

				matchFlag = true;
			}
            else
            {
                int candidate_to_replace = FindLeastPreferredCandidate(preferableHospital);
                if(CompareResidencyOverHospital(preferableHospital,residency,candidate_to_replace))
                    {
						// change operation
                        std::cout << residency << " will Replace\n";
						RemoveValueFromList(problem->HospitalCapacity[preferableHospital],candidate_to_replace);
						problem->HospitalCapacity[preferableHospital].emplace_back(residency);

						problem->FreeResidents.emplace_back(candidate_to_replace);
						matchFlag = true;
						// win
						break;
					}
                    else
                    {
                        std::cout << residency << " Lost\n";

					}


                /*
				// already have another and capacity is full
				for(int i{ 0 }; i < problem->HospitalCapacity[preferableHospital].size(); ++i)
                {
					int versusResidency{ problem->HospitalCapacity[preferableHospital][i] };
                    
                    
                    std::cout << "Comparing resident " << residency << " to resident " << versusResidency << " in hospital " << preferableHospital << ",    " ;
					if(CompareResidencyOverHospital(preferableHospital,residency,versusResidency))
                    {
						// change operation
                        std::cout << residency << " will Replace\n";
						RemoveValueFromList(problem->HospitalCapacity[preferableHospital],versusResidency);
						problem->HospitalCapacity[preferableHospital].emplace_back(residency);

						problem->FreeResidents.emplace_back(versusResidency);
						matchFlag = true;
						// win
						break;
					}
                    else
                    {
                        std::cout << residency << " Lost\n";

					}
				}
                */
			}
		}

        RemoveValueFromList(problem->FreeResidents,residency);
	}

	// for (int hospitalIndex{0}; hospitalIndex < problem->HospitalCapacity.size(); ++hospitalIndex){
	// 	MatchResults.emplace_back(std::vector<int>{});
	// 	for (int i{0}; i < problem->HospitalCapacity[hospitalIndex].size(); ++i)
	// 		MatchResults[hospitalIndex].emplace_back(problem->HospitalCapacity[hospitalIndex][i]);
	// }	
    for(int i{ 0 }; i < problem->HospitalCapacity.size(); ++i){
		for(int j{0}; j < problem->HospitalCapacity[i].size(); ++j){
			MatchResults[i].emplace_back(problem->HospitalCapacity[i][j]);	
		}
	}
}
    

std::string to_format(const int number) {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}

void AlgorithmSolver::OutputResult(){
	for (int i{0}; i < MatchResults.size(); ++i){

        std::cout << "Hospital " << i+1 << " ------- Residences:"; 

		for (int j{0}; j < MatchResults[i].size(); ++j){
			if (j != MatchResults[i].size() - 1)
				std::cout << to_format(MatchResults[i][j]) << " ";
			else
				std::cout << to_format(MatchResults[i][j]) << std::endl;
		}
	}
}
