/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:04 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 18:31:35 by loruzqui         ###   ########.fr       */
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

Fixed::Fixed(Fixed const &copy)
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

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator>(Fixed const &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator<(Fixed const &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>=(Fixed const &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<=(Fixed const &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator==(Fixed const &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(Fixed const &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

//returns a reference to the object
Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//returns a copy of the object
Fixed	Fixed::operator++(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

Fixed	Fixed::operator--(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}

//we used it when the arguments are constant or you do not want to modify the returned object
Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

//we used it when you want to modify the minimum object returned
const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
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
