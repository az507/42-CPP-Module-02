#include "Fixed.hpp"

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

Fixed::Fixed( float const fpnum ) : fixedPtNbr( roundf(fpnum * powf(2.0f, fracBitsNbr)) )
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const& obj )
{ 
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &obj)
		this->fixedPtNbr = obj.getRawBits();

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

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fixedPtNbr) / powf(2.0, fracBitsNbr));
}

int	Fixed::toInt( void ) const
{
	return (this->fixedPtNbr / powf(2.0f, fracBitsNbr));
}

std::ostream&	operator<<( std::ostream& os, Fixed const& obj )
{
	os << obj.toFloat();
	return (os);
}

