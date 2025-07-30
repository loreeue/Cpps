/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:46 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:04:46 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("(null)"), _hit_points(100), _energy_points(100), _attack_damage(30)
{
	std::cout << GREEN << "ClapTrap " << this->_name << " was created with default constructor." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _hit_points(100), _energy_points(100), _attack_damage(30)
{
	std::cout << GREEN << "ClapTrap " << this->_name << " was created." << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap " << this->_name << " was destroyed." << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap " << this->_name << " was copied." << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	this->_name = copy.getName();
	this->_hit_points = copy.getHitPoints();
	this->_energy_points = copy.getEnergyPoints();
	this->_attack_damage = copy.getAttackDamage();
	return (*this);
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

int const	&ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

int const	&ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

int const	&ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::setName(const std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(const int hit_points)
{
	this->_hit_points = hit_points;
}

void	ClapTrap::setEnergyPoints(const int energy_points)
{
	this->_energy_points = energy_points;
}

void	ClapTrap::setAttackDamage(const int attack_damage)
{
	this->_attack_damage = attack_damage;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name << " attacked " << target << ", causing " << this->_attack_damage << " points of damage!" << RESET << std::endl;
		this->_energy_points--;
	}
	if (this->_hit_points <= 0)
		std::cout << "Cannot attack because ClapTrap " << this->_name << " is dead!" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "Cannot attack because ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << RESET << std::endl;
		this->_hit_points -= amount;
	}
	else
		std::cout << "Cannot take damage because ClapTrap " << this->_name << " is already dead!" << std::endl;
	if (this->_hit_points < 0)
		this->_hit_points = 0;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name << " earn " << amount << " points!" << RESET << std::endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	if (this->_hit_points <= 0)
		std::cout << "Cannot repair because ClapTrap " << this->_name << " is dead!" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "Cannot repair because ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}
