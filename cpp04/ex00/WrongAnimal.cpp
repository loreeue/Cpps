/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:34 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:21:53 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("(null)")
{
	std::cout << GREEN << "A wrong animal was created with default constructor." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type): _type(type)
{
	std::cout << GREEN << "A wrong " << this->_type << " was created." << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "A wrong " << this->_type << " was destroyed." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "A wrong " << copy.getType() << " was copied." << std::endl;
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->_type = copy.getType();
	return (*this);
}

std::string const	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(const std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "A wrong animal made a sound :)" << std::endl;
}
