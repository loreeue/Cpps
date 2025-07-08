/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:06:22 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/27 09:23:02 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
Initialization list:
	- For initialize attributes of a class directly in the constructor, before the constructor body executes
*/
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA with name " << this->_name << " and weapon " << this->_weapon.getType() << " has been created!" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA with name " << this->_name << " and weapon " << this->_weapon.getType() << " has been destroyed!" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
