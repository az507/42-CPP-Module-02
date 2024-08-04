#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	bool	flag;

	std::cout << std::boolalpha;

	Point	a(123.2f, 42.42f);
	Point	b(-123.2f, 213.0f);
	Point	c(123.2f, 42.3421f);
	Point	d(123.2f, -90192.1f);

	flag = bsp(a, b, c, d);
	std::cout << "flag: " << flag << std::endl;

	a = Point(1.0f, 2.0f);
	b = Point(3.0f, -5.0f);
	c = Point(-2.4f, 4.2f);
	//d = Point(0.45f, 2.1f);
	d = Point(-123.0f, -400.954f);
	flag = bsp(a, b, c, d);
	std::cout << "flag: " << flag << std::endl;

	flag = bsp(Point(0.0f, 10.0f), Point(10.0f, 0.0f), Point(-5.0f, -5.0f),
			Point(0.0f, 0.0f));
	std::cout << "flag: " << flag << std::endl;
}
