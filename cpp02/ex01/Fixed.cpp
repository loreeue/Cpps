/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:04 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 17:31:18 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (exp == 0)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	exp--;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

const int	Fixed::_frac = 8; //because is static

Fixed::Fixed(void): _value(0) //is inicialized with 0
{
	std::cout << "A new fixed has been created with default constructor!" << std::endl;
}

Fixed::Fixed(const int value): _value(value * ft_pow(2, this->_frac)) //is inicialized with the pow
{
	std::cout << "A new fixed has been created with an int value!" << std::endl;
}

Fixed::Fixed(const float value): _value(roundf(value * ft_pow(2, this->_frac)))
{
	std::cout << "A new fixed has been created with a float value!" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "A new fixed has been destroyed" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "A new fixed has been copied" << std::endl;
	*this = copy;
}

//multiplico por 2⁸ = 256
float	Fixed::toFloat(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

//multiplico por 2⁸ = 256
int	Fixed::toInt(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
