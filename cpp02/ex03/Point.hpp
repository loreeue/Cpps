/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:42:44 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 19:06:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(Point const &copy);
		Point(const float value1, const float value2);
		~Point(void);

		Point		&operator=(Point const &copy);
		Fixed const	&getX(void)const;
		Fixed const	&getY(void)const;
};

std::ostream	&operator<<(std::ostream &str, Point const point); //for the operator <<

#endif
