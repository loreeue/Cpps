/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:14:42 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:29:13 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->setName("(default_clap_name)");
	std::cout << GREEN << "DiamondTrap " << this->getName() << " was created with default constructor." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	this->setName(name);
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << GREEN << "DiamondTrap " << this->getName() << " was created." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap " << this->getName() << " was destroyed." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "Diamond " << this->getName() << " was copied." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << "Assignment operator for DiamondTrap called." << std::endl;
	FragTrap::operator=(copy);
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->getHitPoints() > 0)
	{
		std::cout << YELLOW << "DiamondTrap name: " << this->getName() << "." << RESET << std::endl;
		std::cout << YELLOW << "ClapTrap name: " << ClapTrap::getName() << "." << RESET << std::endl;
	}
	else
		std::cout << "Cannot run whoAmI because DiamondTrap " << this->getName() << " is dead!" << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

std::string const	&DiamondTrap::getName(void) const
{
	return (this->_name);
}

void	DiamondTrap::setName(const std::string name)
{
	this->_name = name;
}
