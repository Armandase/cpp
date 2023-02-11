#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed{
	public:
		Fixed();
		Fixed(const int param);
		Fixed(const float param);
		Fixed(const Fixed &copy);
		Fixed& operator = (const Fixed& fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					_int;
		static const int	_fract;
};

#endif
