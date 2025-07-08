/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:05:56 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/30 19:13:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon of type " << this->_type << " has been created!" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon of type " << this->_type << " has been destroyed!" << std::endl;
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
