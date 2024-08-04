#include "Fixed.hpp"

int	main(void)
{
	/*
	Fixed	a(100.1231f);
	Fixed	b(0);

	std::cout << std::boolalpha;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << --b << std::endl;
	std::cout << b << std::endl;
	std::cout << b++ << std::endl;
	std::cout << b << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;

	const Fixed	c(-312.241f);
	const Fixed	d(9192.1f);
	std::cout << "Fixed::min(c, d) = " << Fixed::min(c, d) << std::endl;
	std::cout << "Fixed::max(c, d) = " << Fixed::max(c, d) << std::endl;
	*/
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << a / Fixed( 0 ) << std::endl;
	return 0;
}
