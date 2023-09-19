#include "Input.h"

std::vector<std::vector<int>> read_hospital_file(std::string hospital_filepath)
{
	std::ifstream hos_file;

	hos_file.open(hospital_filepath);

    std::string line;
    std::vector<std::vector<int>> store;

    while (std::getline(hos_file, line))
    {
        std::istringstream iss(line);
        store.push_back(
            std::vector<int>(std::istream_iterator<int>(iss),
                std::istream_iterator<int>()));
    }

    hos_file.close();

    return store;
}


void printValues(std::vector<std::vector<int>>input )
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

std::vector<std::vector<int>> read_residents_file(std::string residences_filepath)
{
    std::ifstream res_file;

    res_file.open(residences_filepath);

    std::string line;
    std::vector<std::vector<int>> store;

    while (std::getline(res_file, line))
    {
        std::istringstream iss(line);
        store.push_back(
            std::vector<int>(std::istream_iterator<int>(iss),
                std::istream_iterator<int>()));
    }

    res_file.close();

    return store;

}

std::string to_format(const int number) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}
