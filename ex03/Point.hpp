#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point( void );
		Point( float const, float const );
		Point( Point const& );

		Point&	operator=( Point const& );
		
		~Point(void);

};

#endif
