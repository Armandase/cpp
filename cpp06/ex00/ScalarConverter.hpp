#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	 public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter (const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter&);
		ScalarConverter(char *str);

		void	print();
	 private:
		std::string	_str;
		int		findType(char *str);
		bool	isChar(char *str);
		bool	isInt(char *str);
		bool	isFloat(char *str);
		bool	isDouble(char *str);
		char	_c;
		int		_i;
		float	_f;
		double	_d;
		int		_special;
		enum{
			_nanf,
			_posInff,
			_negInff,
			_nan,
			_posInf,
			_negInf
		};
};

#endif
