#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
#include <cstring>

class BitcoinExchange
{
	 public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange (const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange&);
		void	getDataBase();
		void	getInputFile(char *av);
		class WrongData : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Error in data.csv");
			}
		};
	 private:
		bool	checkDate(std::string line);
		void	displayLine(std::string line);
		std::map<std::string, float>	data;
		std::string						date;
		float							value;
		
};

#endif
