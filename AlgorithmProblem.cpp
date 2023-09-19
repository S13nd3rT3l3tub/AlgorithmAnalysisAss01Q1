#include "AlgorithmProblem.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>

void AlgorithmProblem::Load(std::string hospital_filepath, std::string residences_filepath, int _maxCapacity) {
	this->hospital_data_filepath = hospital_filepath;
	this->residence_data_filepath = residences_filepath;
	this->maxCapacity = _maxCapacity;

	Init();

	std::cout << "------------------Read Data------------------\n";
	printValues();
	std::cout << "---------------------------------------------\n";
}

void AlgorithmProblem::Init(){
	read_hospital_file(hospital_data_filepath);
	read_residents_file(residence_data_filepath);
}

void AlgorithmProblem::read_hospital_file(std::string hospital_filepath)
{
	int index{ 1 };

	std::ifstream hos_file;
	hos_file.open(hospital_filepath);

	std::string line;
	while (std::getline(hos_file, line))
	{
		std::istringstream iss(line);
		Hospitals.emplace(index,
			std::vector<int>(std::istream_iterator<int>(iss),
				std::istream_iterator<int>()));

		HospitalCapacity.emplace(index, std::vector<int>{});
		++index;
	}

	hos_file.close();
}

void AlgorithmProblem::read_residents_file(std::string residences_filepath)
{
	int index{ 1 };

	std::ifstream res_file;
	res_file.open(residences_filepath);

	std::string line;
	while (std::getline(res_file, line))
	{
		std::istringstream iss(line);
		Residents.emplace(index, 
			std::vector<int>(std::istream_iterator<int>(iss),
				std::istream_iterator<int>()));
		// ResidentsPreference.emplace(index, 
		// 	std::vector<int>(std::istream_iterator<int>(iss),
		// 		std::istream_iterator<int>()));
		FreeResidents.push_back(index);
		++index;
	}

	res_file.close();
}

void AlgorithmProblem::printValues(){
	printValues(this->Hospitals);
	std::cout << std::endl;
	printValues(this->Residents);
    //std::cout << std::endl;
    //printValues(this->ResidentsPreference);
}

void AlgorithmProblem::printValues(std::unordered_map<int, std::vector<int>> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (j != (input[i].size() - 1))
				std::cout << to_format(input[i][j]) << " ";
			else
				std::cout << to_format(input[i][j]) << std::endl;
		}
	}
}

std::string AlgorithmProblem::to_format(const int number) {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}
