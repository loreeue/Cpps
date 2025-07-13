/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:42:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 19:43:07 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) //is inicialized with 0
{
	std::cout << "A new point has been created with default constructor!" << std::endl;
}

Point::Point(const float value1, const float value2): _x(value1), _y(value2)
{
	std::cout << "A new point has been created!" << std::endl;
}

Point::~Point(void)
{
	std::cout << "A new point has been destroyed" << std::endl;
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
	std::cout << "Point Copy Constructor called" << std::endl;
}

Point &Point::operator=(const Point &src)
{
	std::cout << "Point Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

Fixed const	&Point::getX(void) const
{
	return (this->_x);
}

Fixed const	&Point::getY(void) const
{
	return (this->_y);
}

std::ostream	&operator<<(std::ostream &str, Point const point)
{
	str << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (str);
}
