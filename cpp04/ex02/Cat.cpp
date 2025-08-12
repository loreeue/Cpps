/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:57 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 18:32:41 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat")
{
	this->_brain = new Brain();
	std::cout << GREEN << "A " << AAnimal::getType() << " was created with default constructor." << RESET << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << RED << "A " << AAnimal::getType() << " was destroyed." << RESET << std::endl;
}

Cat::Cat(Cat const &copy): AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << "A " << AAnimal::getType() << " was copied." << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Brain &Cat::getBrain(void) const
{
	return (*this->_brain);
}

void	Cat::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "miau, miau, miau, ..." << std::endl;
}
