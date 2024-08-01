#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <climits>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const& );
		Fixed( int const );
		Fixed( float const );
		~Fixed( void );

		Fixed&	operator=( Fixed const& );

		bool	operator<( Fixed const& ) const;
		bool	operator>( Fixed const& ) const;
		bool	operator>=( Fixed const& ) const;
		bool	operator<=( Fixed const& ) const;
		bool	operator==( Fixed const& ) const;
		bool	operator!=( Fixed const& ) const;

		Fixed	operator+( Fixed const& );
		Fixed	operator-( Fixed const& );
		Fixed	operator*( Fixed const& );
		Fixed	operator/( Fixed const& );

		Fixed&	operator++( void );
		Fixed	operator++( int );

		Fixed&	operator--( void );
		Fixed	operator--( int );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int	toInt( void ) const;

		static Fixed&	min( Fixed&, Fixed& );
		static Fixed&	min( Fixed const&, Fixed const& );

		static Fixed&	max( Fixed&, Fixed& );
		static Fixed&	max( Fixed const&, Fixed const& );

	private:
		int			fixedPtNbr;
		static const int	fracBitsNbr = 8;
		static const float	convertRatio;
};

std::ostream&	operator<<( std::ostream& os, Fixed const& obj );

#endif
