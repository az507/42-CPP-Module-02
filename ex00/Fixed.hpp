#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &);

		Fixed	&operator=(const Fixed &);

		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int			_nbr;
		static const int	_fracbits = 8;

};

#endif
