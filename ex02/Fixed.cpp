#include "Fixed.hpp"

const float	Fixed::convertRatio = powf( 2.0f, fracBitsNbr );


Fixed::Fixed( void ) : fixedPtNbr( 0 )
{
	std::cout << "Default constructor called"  << std::endl;
}


Fixed::Fixed( Fixed const& copy )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}


Fixed::Fixed( int const num ) : fixedPtNbr( num << fracBitsNbr )
{
	std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed( float const fpnum ) : fixedPtNbr( roundf(fpnum * convertRatio) )
{
	std::cout << "Float constructor called" << std::endl;
}


Fixed&	Fixed::operator=( Fixed const& obj )
{ 
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &obj)
		this->fixedPtNbr = obj.getRawBits();

	return ( *this );
}


bool	Fixed::operator>( Fixed const& obj ) const
{
	return ( this->toFloat() > obj.toFloat() );
}


bool	Fixed::operator<( Fixed const& obj ) const
{
	return ( this->toFloat() < obj.toFloat() );
}


bool	Fixed::operator>=( Fixed const& obj ) const
{
	return ( *this > obj || *this == obj );
}


bool	Fixed::operator<=( Fixed const& obj ) const
{
	return ( *this < obj || *this == obj );
}


bool	Fixed::operator==( Fixed const& obj ) const
{
	return ( this->toFloat() == obj.toFloat() );
}


bool	Fixed::operator!=( Fixed const& obj ) const
{
	return !( *this == obj );
}


Fixed	Fixed::operator+( Fixed const& other )
{
	Fixed	f;

	f.fixedPtNbr = this->fixedPtNbr + other.fixedPtNbr;
	return ( f );
}


Fixed	Fixed::operator-( Fixed const& other )
{
	Fixed	f;

	f.fixedPtNbr = this->fixedPtNbr - other.fixedPtNbr;
	return ( f );
}


Fixed	Fixed::operator*( Fixed const& other )
{
	Fixed	f;

	f.setRawBits( roundf( ( this->toFloat() * other.toFloat() )
			* powf( 2.0f, fracBitsNbr ) ) );
	return ( f );
}


Fixed	Fixed::operator/( Fixed const& other )
{
	Fixed	f;

	f.setRawBits( roundf( ( this->toFloat() / other.toFloat() )
			* powf( 2.0f, fracBitsNbr ) ) );
	return ( f );
}


Fixed&	Fixed::operator++( void )
{
	this->fixedPtNbr++;

	return ( *this );
}


Fixed	Fixed::operator++( int )
{
	Fixed	instance( *this );
	++*this;

	return ( instance );
}


Fixed&	Fixed::operator--( void )
{
	this->fixedPtNbr--;

	return ( *this );

}


Fixed	Fixed::operator--( int )
{
	Fixed	instance( *this );
	--*this;

	return ( instance );
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return ( this->fixedPtNbr );
}


void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->fixedPtNbr = raw;
}


float	Fixed::toFloat( void ) const
{
	return ( static_cast<float>(this->fixedPtNbr) / convertRatio );
}


int	Fixed::toInt( void ) const
{
	return ( this->fixedPtNbr / convertRatio );
}


Fixed&	Fixed::min( Fixed& f1, Fixed& f2 )
{
	Fixed&	f3 = ( f1 < f2 ) ? f1 : f2;

	return ( f3 );
}


Fixed&	Fixed::min( Fixed const& f1, Fixed const& f2 )
{
	Fixed&	f3 = (f1 < f2) ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2);
	
	return (f3);
}


Fixed	&Fixed::max(Fixed &f1, Fixed& f2)
{
	Fixed	&f3 = (f1 > f2) ? f1 : f2;

	return (f3);
}


Fixed&	Fixed::max(Fixed const& f1, Fixed const& f2)
{
	Fixed&	f3 = (f1 > f2) ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2);

	return (f3);
}


std::ostream&	operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();

	return (os);
}
