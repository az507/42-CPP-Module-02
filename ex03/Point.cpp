#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{

}

Point::Point(const float n1, const float n2) : x(n1), y(n2)
{

}

Point::Point(const Point &obj)
{
	*this = obj;
}

Point	&Point::operator=(const Point &obj)
{
	if (this != &obj)
	{
		const_cast<Fixed &>(this->x) = obj.x;
		const_cast<Fixed &>(this->y) = obj.y;
	}
	return (*this);
}

Point	Point::operator-(const Point &obj) const
{
	if (this == &obj)
		return (Point());

	return (Point(this->getFloatX() - obj.getFloatX(),
			this->getFloatY() - obj.getFloatY()));
}

Point::~Point(void)
{

}

float	Point::getFloatX(void) const
{
	return (this->x.toFloat());
}

float	Point::getFloatY(void) const
{
	return (this->y.toFloat());
}

std::ostream	&operator<<(std::ostream &os, const Point &obj)
{
	os << "x: " << obj.getFloatX() << ", y: " << obj.getFloatY();
	return (os);
}
