#include "Fixed.hpp"

void	printInBinary( int num )
{
	std::size_t	bitsNbr = sizeof(int) * CHAR_BIT;

	for (std::size_t i = 0; i < bitsNbr; ++i)
	{
		if (i == 1 || i == 3 * bitsNbr / 4)
			std::cout << "  ";
		std::cout << ((num >> (bitsNbr - i - 1)) & 0b1);
	}

	std::cout << std::endl;
}

int	main( void )
{
	Fixed	a;
	Fixed const b( -10 );
	Fixed const c( -42.42f );
	Fixed const d( b );
	Fixed	e;

	a = Fixed( -1234.4321f );
	e = Fixed( -1.5f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;

	/*
	float	num = -1234.4321f;
	int	temp;

	printInBinary(num);
	std::cout << "num: " << num << std::endl;

	temp = roundf(num * powf(2.0f, 8.0f));
	printInBinary(temp);
	std::cout << "temp: " << temp << std::endl;

	temp >>= 8;
	printInBinary(temp);
	std::cout << "temp: " << temp << std::endl;

	int	abc = -1234;

	std::cout << abc << std::endl;

	abc <<= 8;
	std::cout << abc << std::endl;

	abc >>= 8;
	std::cout << abc << std::endl;
	*/

	printInBinary(-1 >> 1);
	printInBinary(-1 >> 2);

	std::cout << (-1 >> 1) << std::endl;
	std::cout << (-1 >> 2) << std::endl;
	std::cout << (-1 >> 3) << std::endl;
}

