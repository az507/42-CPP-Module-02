#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);

		Fixed	&operator=(const Fixed &);
		bool	operator<(const Fixed &) const;
		bool	operator>(const Fixed &) const;
		bool	operator<=(const Fixed &) const;
		bool	operator>=(const Fixed &) const;
		bool	operator==(const Fixed &) const;
		bool	operator!=(const Fixed &) const;
		Fixed	operator+(const Fixed &) const;
		Fixed	operator-(const Fixed &) const;
		Fixed	operator*(const Fixed &) const;
		Fixed	operator/(const Fixed &) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed	&min(Fixed &, Fixed &);
		static Fixed	&min(const Fixed &, const Fixed &);
		static Fixed	&max(Fixed &, Fixed &);
		static Fixed	&max(const Fixed &, const Fixed &);

	private:
		int			_nbr;
		static const int	_fracbits = 8;
		static const float	_scale;

};

std::ostream	&operator<<(std::ostream &, const Fixed &);

#endif
