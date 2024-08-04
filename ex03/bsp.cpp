#include "Point.hpp"

double	findDeterminant(const Point &v1, const Point &v2)
{
	std::cout << "v1, " << v1 << std::endl;
	std::cout << "v2, " << v2 << std::endl;
	return ((v1.getFloatX() * v2.getFloatY()) - (v1.getFloatY() * v2.getFloatX()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	double	*res = new double [3];
	bool	in_triangle = false;

	res[0] = findDeterminant(b - a, point - a);
	res[1] = findDeterminant(c - b, point - b);
	res[2] = findDeterminant(a - c, point - c);

	std::cout << "res[0]: " << res[0] << std::endl;
	std::cout << "res[1]: " << res[1] << std::endl;
	std::cout << "res[2]: " << res[2] << std::endl;

	if (std::signbit(res[0]) && std::signbit(res[1]) && std::signbit(res[2])
		&& res[0] != -0.0 && res[1] != -0.0 && res[2] != -0.0)
		in_triangle = true;

	delete [] res;

	return (in_triangle);
}
