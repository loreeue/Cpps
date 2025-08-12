/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:42 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 12:44:12 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << GREEN << "A " << Animal::getType() << " was created with default constructor." << RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << RED << "A " << Animal::getType() << " was destroyed." << RESET << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	std::cout << "A " << Animal::getType() << " was copied." << std::endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->_type = copy.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "guau, guau, guau, ..." << std::endl;
}
