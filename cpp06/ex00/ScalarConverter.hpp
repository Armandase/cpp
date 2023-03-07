#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
	 public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter (const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter&);
		ScalarConverter(char *str);

		void	convert(char *toConvert);
	 private:
		int		findType(char *str);
		bool	isChar(char *str);
		bool	isInt(char *str);
		bool	isFloat(char *str);
		bool	isDouble(char *str);
		char	_c;
		int		_i;
		float	_f;
		double	_d;
};

#endif
