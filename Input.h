#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

std::vector<std::vector<int>> read_hospital_file(std::string hospital_filepath);


std::vector<std::vector<int>> read_residents_file(std::string residences_filepath);


void printValues(std::vector<std::vector<int>> input);


std::string to_format(const int number);