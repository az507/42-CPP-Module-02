#include "Fixed.hpp"

const float	Fixed::_scale = powf(2.0f, _fracbits);

Fixed::Fixed(void) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int num) : _nbr(num << _fracbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _nbr(roundf(num * _scale))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_nbr = obj._nbr;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbr = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_nbr / _scale);
}

int	Fixed::toInt(void) const
{
	return (this->_nbr >> _fracbits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}
