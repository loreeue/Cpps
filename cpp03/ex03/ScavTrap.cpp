/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:48:45 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:23:45 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << GREEN << "ScavTrap from ClapTrap " << this->getName() << " was created with default constructor." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap from ClapTrap " << this->getName() << " was created." << RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap from ClapTrap " << this->getName() << " was destroyed." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap from ClapTrap " << this->getName() << " was copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Assignment operator for ScavTrap called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->getHitPoints() > 0)
		std::cout << YELLOW << "ScavTrap from ClapTrap " << this->getName() << " switched to mode: \"Guard Gate\"!" << RESET << std::endl;
	else
		std::cout << "Cannot switch to gate-keeper mode because ClapTrap " << this->getName() << " is dead!" << std::endl;
}
