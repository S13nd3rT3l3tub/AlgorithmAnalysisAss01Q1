#ifndef ALGORITHMPROBLEM
#define ALGORITHMPROBLEM

#include <vector>
#include <unordered_map>
#include <string>

class AlgorithmProblem {
public:
	std::string hospital_data_filepath,
				residence_data_filepath;
	std::unordered_map<int, std::vector<int>>	Hospitals,
												HospitalCapacity,
												Residents,
												//ResidentsPreference,
												Results;
	std::vector<int> FreeResidents;
	int maxCapacity;

	void Load(std::string hospital_filepath, std::string residences_filepath, int _maxCapacity);
	void Init();
	void read_hospital_file(std::string hospital_filepath);
	void read_residents_file(std::string residences_filepath);
	void printValues();
	void printValues(std::unordered_map<int, std::vector<int>> input);
	std::string to_format(const int number);
};

#endif