#include "Account.hpp"
#include <ctime>
#include <sstream>

void	Account::_displayTimestamp(void){
	struct tm	time;
	std::string	date;
	std::stringstream toInt;

	toInt << (time.tm_year + 1900);
	date + toInt.str();
	toInt << (time.tm_mon + 1);
	date + toInt.str();
	toInt << (time.tm_mday);
	date + toInt.str() + "_";
	toInt << (time.tm_hour);
	date + toInt.str();
	toInt << (time.tm_min);
	date + toInt.str();
	toInt << (time.tm_sec);
	date + toInt.str();
}
