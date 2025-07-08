/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:06:44 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/27 09:22:54 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
Initialization list:
	- For initialize attributes of a class directly in the constructor, before the constructor body executes
*/
HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << "HumanB with name " << this->_name << " has been created!" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB with name " << this->_name << " has been destroyed!" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
