/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:04 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 16:33:12 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0) //is inicialized with 0
{
	std::cout << "A new fixed has been created with default constructor!" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "A new fixed has been destroyed" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "A new fixed has been copied" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "A new assignment operator has been called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function has been called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}
