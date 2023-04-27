#include "BitcoinExchange.hpp"
#include <list>
#include <stdexcept>

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
	long		mounth;
	char		*cmp;
	int			verif[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

	date = line.substr(0, line.find("-"));
	tmp = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || tmp < 2009 || tmp > 2030){
		return (false);
	}
	if ((tmp % 4 == 0 && tmp % 100 != 0) || tmp % 400 == 0)
		verif[1]++;
	date = line.substr(date.length() + 1, line.find("-") - 1);
	mounth = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || mounth > 12 || mounth < 1){
		return (false);
	}
	date = line.substr(line.substr(0, line.find("-")).length() + 1 + date.length(), line.find(" ") - 1);
	tmp = std::strtol(date.c_str(), &cmp, 10);
	if (cmp == date || tmp < 1 || tmp > verif[mounth - 1]){
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
		data.insert(std::pair<std::string, float>(line.substr(0, line.find(",")), std::atof(line.substr(line.find(",") + 1, line.find("\n")).c_str())));
		i++;
	}
	if (data.size() == 0)
		throw std::logic_error("Error: empty data");
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

	std::map<std::string, float>::iterator it;

	it = data.upper_bound(date);
	it--;
	std::cout << date << " => " << value;
	std::cout << " = " << value * it->second << std::endl;
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
		{}
		else if (line == "date | value")
			std::cout << "Error: random header" << std::endl;
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
	if (i <= 1)
		std::cout << "Error: empty file" << std::endl;
}
