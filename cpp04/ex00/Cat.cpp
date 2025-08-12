/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:57 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:04:37 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << GREEN << "A " << Animal::getType() << " was created with default constructor." << RESET << std::endl;
}

Cat::~Cat(void)
{
	std::cout << RED << "A " << Animal::getType() << " was destroyed." << RESET << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy)
{
	std::cout << "A " << Animal::getType() << " was copied." << std::endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat &copy)
{
	this->_type = copy.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "miau, miau, miau, ..." << std::endl;
}
