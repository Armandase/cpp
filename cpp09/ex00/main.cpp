#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <cstring>

bool	checkDate(std::string line){
	std::string	date;
	long		tmp;
	char		*cmp;

	date = line.substr(0, line.find("-"));
	tmp = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || tmp < 0 || tmp > 2030){
		return (false);
	}
	date = line.substr(date.length() + 1, line.find("-") - 1);
	tmp = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || tmp > 12 || tmp < 1){
		return (false);
	}
	date = line.substr(line.substr(0, line.find("-")).length() + 1 + date.length(), line.find(" ") - 1);
	tmp = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || tmp > 31 || tmp < 1){
		return (false);
	}
	return (true);
}

bool	checkNumber(std::string line){
	std::string	number;
	long		nu;
	char		*cmp;

	number = line.substr(line.find("|") + 1, line.length());
	nu = std::strtol(number.c_str(), &cmp, 10);
	if (cmp == number || nu < 0 || nu > 1000){
		return (false);
	}
	return (true);
}

void	displayResult(std::string line){}

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
		if (line == "date | value")
			continue ;
		else if (line.find("|") == std::string::npos)
			std::cout << "Error: Wrong format" << std::endl;
		else if (checkDate(line) == false)
			std::cout << "Error: wrong date format" << std::endl;
		else if (checkNumber(line) == false)
			std::cout << "Error: wrong value" << std::endl;
		else
			displayResult(line);
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
