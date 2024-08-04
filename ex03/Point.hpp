#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const float, const float);
		Point(const Point &);

		Point	&operator=(const Point &);
		Point	operator-(const Point &) const;

		~Point(void);

		float	getFloatX(void) const;
		float	getFloatY(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

std::ostream	&operator<<(std::ostream &, const Point &);

#endif
