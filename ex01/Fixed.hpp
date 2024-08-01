#pragma once

#include <iostream>
#include <cmath>
#include <climits>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const& );
		Fixed( int const );
		Fixed( float const );
		~Fixed( void );

		Fixed&	operator=( Fixed const& );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int	toInt( void ) const;

	private:
		int			fixedPtNbr;
		static const int	fracBitsNbr = 8;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& obj );
