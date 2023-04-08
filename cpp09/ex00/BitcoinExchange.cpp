#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	this->data = copy.data;
	this->date = copy.date;
	this->value = copy.value;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy){
	this->data = copy.data;
	this->date = copy.date;
	this->value = copy.value;
	return(*this);
}


bool	BitcoinExchange::checkDate(std::string line){
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

bool	checkNumber(std::string line, std::string split, int max){
	std::string	number;
	long		nu;
	char		*cmp;

	number = line.substr(line.find(split) + 1, line.length());
	if (number.find_first_not_of("0123456789. ") != std::string::npos || *number.rbegin() == '.')
		return (false);
	nu = std::strtol(number.c_str(), &cmp, 10);
	if (cmp == number || nu < 0 || nu > max){
		return (false);
	}
	return (true);
}

void	BitcoinExchange::getDataBase(){
	std::ifstream	fileData;
	int		i = 0;

	fileData.open("data.csv");
	if (!fileData){
		std::cerr << "Error: open data.csv" << std::endl;
		std::exit(1);
	}
	std::string line;
	while (std::getline(fileData, line)){
		if (line == "date,exchange_rate" && i == 0)
			continue ;
		else if (line.find(",") == std::string::npos)
			throw BitcoinExchange::WrongData();
		else if (checkDate(line) == false)
			throw BitcoinExchange::WrongData();
		else if (checkNumber(line, ",", 2147483647) == false)
			throw BitcoinExchange::WrongData();
		data[line.substr(0, line.find(","))] = std::atof(line.substr(line.find(",") + 1, line.find("\n")).c_str());
		i++;
	}
}

void	BitcoinExchange::displayLine(std::string line){
	std::map<std::string, float>::iterator in;
	std::map<std::string, float>::iterator next;
	std::string	number;
	char		*cmp;

	date = line.substr(0, line.find(" | "));
	if (date.length() == line.length()){
		std::cout << "Error: wrong date format" << std::endl;
		return ;
	}
	number = line.substr(line.find("|") + 2, line.size());
	value = std::strtof(number.c_str(), &cmp);

	for (in = data.begin(); in != data.end(); in++){
		next = in;
		std::advance(next, 1);
		if (in->first == date ||
				(next != data.end() && ((next->first <= date && in->first >= date)
				 || (next->first >= date && in->first <= date)))){
			std::cout << date << " => " << value;
			std::cout << " = " << value * in->second << std::endl;
			return ;
		}
	}
	std::cout << "Error: no matching date" << std::endl;
}

void	BitcoinExchange::getInputFile(char *av)
{
	std::ifstream 	file;
	int		i = 0;

	file.open(av);
	if (!file){
		std::cerr << "Error: open input file" << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(file, line)){
		if (line == "date | value" && i == 0)
			continue ;
		else if (line.find("|") == std::string::npos)
			std::cout << "Error: wrong format" << std::endl;
		else if (checkDate(line) == false)
			std::cout << "Error: wrong date format" << std::endl;
		else if (checkNumber(line, "|", 1000) == false)
			std::cout << "Error: wrong value" << std::endl;
		else
			displayLine(line);
		i++;
	}
}
