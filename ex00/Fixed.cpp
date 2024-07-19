#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPtNbr( 0 )
{
	std::cout << "Default constructor called"  << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}

Fixed&	Fixed::operator=( const Fixed& obj )
{ 
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &obj)
		return (*this);

	fixedPtNbr = obj.getRawBits();

	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->fixedPtNbr);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->fixedPtNbr = raw;
}

