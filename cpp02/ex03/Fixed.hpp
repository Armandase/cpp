#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>

class Fixed{
	public:
		Fixed();
		~Fixed();
		Fixed(const int param);
		Fixed(const float param);
		Fixed(const Fixed &copy);
		Fixed& operator = (const Fixed& fixed);
		bool operator > (const Fixed& fixed);
		bool operator < (const Fixed& fixed);
		bool operator >= (const Fixed& fixed);
		bool operator <= (const Fixed& fixed);
		bool operator == (const Fixed& fixed);
		bool operator != (const Fixed& fixed);
		Fixed& operator + (const Fixed& fixed);
		Fixed& operator - (const Fixed& fixed);
		Fixed& operator * (const Fixed& fixed);
		Fixed& operator / (const Fixed& fixed);
		Fixed operator ++ (int);//postfix
		Fixed& operator ++ (void);//prefix
		Fixed operator -- (int);
		Fixed& operator -- (void);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					_int;
		static const int	_fract;
};

std::ostream& operator<<(std::ostream& os, const Fixed& data);

#endif
