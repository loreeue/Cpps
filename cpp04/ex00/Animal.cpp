/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:49:46 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:10:20 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("(null)")
{
	std::cout << GREEN << "A animal was created with default constructor." << RESET << std::endl;
}

Animal::Animal(std::string const &type): _type(type)
{
	std::cout << GREEN << "A " << this->_type << " was created." << RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << RED << "A " << this->_type << " was destroyed." << RESET << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "A " << copy.getType() << " was copied." << std::endl;
	*this = copy;
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->_type = copy.getType();
	return (*this);
}

std::string const	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "A animal made a sound :)" << std::endl;
}
