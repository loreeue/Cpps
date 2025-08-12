/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:49:46 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 18:33:32 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("(null)")
{
	std::cout << GREEN << "A animal was created with default constructor." << RESET << std::endl;
}

AAnimal::AAnimal(std::string const &type): _type(type)
{
	std::cout << GREEN << "A " << this->_type << " was created." << RESET << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << RED << "A " << this->_type << " was destroyed." << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "A " << copy.getType() << " was copied." << std::endl;
	*this = copy;
}

AAnimal const	&AAnimal::operator=(const AAnimal &copy)
{
	this->_type = copy.getType();
	return (*this);
}

std::string const	&AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(const std::string type)
{
	this->_type = type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "A animal made a sound :)" << std::endl;
}
