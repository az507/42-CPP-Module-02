#pragma once

#include <iostream>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed& );
		~Fixed( void );

		Fixed&	operator=( const Fixed& );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int			fixedPtNbr;
		static const int	fracBitsNbr = 8;
};
