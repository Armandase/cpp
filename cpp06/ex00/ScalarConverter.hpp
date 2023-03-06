#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
	 public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter (const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter&);
		void	convert(char *toConvert);
	 private:
		char	_c;
		int		_i;
		float	_f;
		double	_d;
		
};

#endif
