/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:42 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/30 12:54:23 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << GREEN << "A " << Animal::getType() << " was created with default constructor." << RESET << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << RED << "A " << Animal::getType() << " was destroyed." << RESET << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << "A " << Animal::getType() << " was copied." << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Brain &Dog::getBrain(void) const
{
	return (*this->_brain);
}

void	Dog::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "guau, guau, guau, ..." << std::endl;
}
