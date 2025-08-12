/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:56:39 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/28 17:08:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << GREEN << "Ice was created with default constructor." << RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << RED << "Ice was destroyed." << RESET << std::endl;
}

Ice::Ice(Ice const &copy): AMateria(copy)
{
	std::cout << "Ice was copied." << std::endl;
	*this = copy;
}

Ice	const &Ice::operator=(const Ice &copy)
{
	this->_type = copy.getType();
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
