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

Fixed::Fixed( int const num ) : fixedPtNbr( num )
{
	std::cout << "Int constructor called" << std::endl;
}

void	printInBinary( int num )
{
	int	bitsNbr = sizeof(int) * CHAR_BIT;

	for (int i = 0; i < bitsNbr; ++i)
	{
		if (i == 1 || i == 3 * bitsNbr / 4)
			std::cout << "  ";
		std::cout << ((num >> (bitsNbr - i - 1)) & 0b1);
	}
	std::cout << std::endl;
}

Fixed::Fixed( float const fpnum ) : fixedPtNbr( 0 )
{
	float	fl_portion;
	float	int_portion;

	fl_portion = modff(fpnum, &int_portion);

	for (int i = 0; i < fracBitsNbr; ++i)
	{
		fl_portion *= 2.0;
		if (fl_portion > 1.0)
		{
			fl_portion -= 1.0;
			this->fixedPtNbr |= (1 << (fracBitsNbr - i - 1));
		}
	}

	this->fixedPtNbr |= static_cast<int>(int_portion) << fracBitsNbr;

	printInBinary(this->fixedPtNbr);
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const& obj )
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

float	Fixed::toFloat( void ) const
{
	float	fl_num = 0;

	for (int i = 0; i < fracBitsNbr; ++i)
	{
		if ((this->fixedPtNbr >> (fracBitsNbr - i - 1)) & 0b1)
			fl_num += powf(2.0, -(i + 1));
	}

	fl_num += this->fixedPtNbr >> fracBitsNbr;
	
	std::cout << "fl_num: " << fl_num << std::endl;

	return (fl_portion);
}

int	Fixed::toInt( void ) const
{
	return (this->fixedPtNbr);
}

std::ostream&	operator<<( std::ostream& os, Fixed const& obj )
{
	os << obj.toFloat();
	return (os);
}

