#ifndef _HARL_HPP_
#define _HARL_HPP_

#include <iostream>

class Harl{
	public:
		void	complain(std::string level);
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

#endif
