/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:56:55 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/28 17:08:13 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << GREEN << "Cure was created with default constructor." << RESET << std::endl;
}

Cure::~Cure(void)
{
	std::cout << RED << "Cure was destroyed." << RESET << std::endl;
}

Cure::Cure(Cure const &copy): AMateria(copy)
{
	std::cout << "Cure was copied." << std::endl;
	*this = copy;
}

Cure	const &Cure::operator=(const Cure &copy)
{
	this->_type = copy.getType();
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
