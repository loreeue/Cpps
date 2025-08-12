/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:56:11 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/28 16:47:02 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	this->_type = type;
	std::cout << GREEN << "AMateria created." << RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << RED << "AMateria destroyed." << RESET << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	std::cout << "AMateria copied." << std::endl;
	*this = copy;
}

AMateria	const &AMateria::operator=(const AMateria &copy)
{
	this->_type = copy._type;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}
