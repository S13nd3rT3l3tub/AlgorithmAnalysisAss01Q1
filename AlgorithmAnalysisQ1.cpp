// AlgorithmAnalysisQ1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "input.h"
#include <iostream>

#include "AlgorithmSolver.h"

int main(int argc, char* argv[]) {


	std::vector<std::vector<int>> hospital;
	std::vector<std::vector<int>> residences;

	hospital = read_hospital_file("data1_hospitals.txt");
	//hospital = read_hospital_file(argv[1]);

	residences = read_hospital_file("data1_residents.txt");

	//residences = read_hospital_file(argv[2]);

	printValues(hospital);
	std::cout << std::endl;
	printValues(residences);


	/*
	if (argc < 4) {
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
	else if (argc == 4) {
		
		<Problem data type> _problem{ argv[1], argv[2], argv[3] };
		<Algorithm data type> _algorithm{ problem };
		_algorithm.match();
		

		


	}
	else {
		std::cout << "Too many arguments given!\n";
		std::cout << "Usage: " << argv[0] << " <datafile_hospital> <datafile_residents> <hospital capacity(int)>\n";
	}
	*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
