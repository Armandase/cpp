#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <cstring>

void	file_parsing(char *av)
{
	std::ifstream file;
	std::map<std::string, float> input;

	file.open(av);
	if (!file){
		std::cerr << "Error: open input file" << std::endl;
		std::exit(1);
	}

	std::string line;
	while (std::getline(file, line)){
		std::string	date;
		long		tmp;
		char		*cmp;
		if (line.find("|") == std::string::npos){
			std::cout << "Error: Wrong format" << std::endl;
		}
		date = line.substr(0, line.find("-"));
		tmp = std::strtol(date.c_str(), &cmp, 10);
		if (cmp == date || tmp > 1000 || tmp < 0)
		{
			std::cout << "Error: too large number" << std::endl;
			std::exit(0);
		}
	}
}

void	data_base(){
	std::ifstream fileData;
	std::map<std::string, float>Data;

	fileData.open("data.csv");
	if (!fileData){
		std::cerr << "Error: open data.csv" << std::endl;
		std::exit(1);
	}
	std::string line;
	while (std::getline(fileData, line)){
		Data[line.substr(0, line.find(","))] = std::atof(line.substr(line.find(",") + 1, line.find("\n")).c_str());
	}
}

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	data_base();
	file_parsing(av[1]);
	return (0);
}
