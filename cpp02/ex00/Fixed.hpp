#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed& operator = (const Fixed& fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_raw;
		static const int	_bits;
};

#endif
