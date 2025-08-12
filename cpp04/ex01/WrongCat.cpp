/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:57 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:23:44 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("Cat")
{
	std::cout << GREEN << "A wrong " << WrongAnimal::getType() << " was created with default constructor." << RESET << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "A wrong " << WrongAnimal::getType() << " was destroyed." << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy)
{
	std::cout << "A wrong " << WrongAnimal::getType() << " was copied." << std::endl;
	*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	this->_type = copy.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "miau, miau, miau, ..." << std::endl;
}
