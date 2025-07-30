/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:00:14 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:20:11 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << GREEN << "FragTrap from ClapTrap " << this->getName() << " was created with default constructor." << RESET << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	std::cout << GREEN << "FragTrap from ClapTrap " << this->getName() << " was created." << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap from ClapTrap " << this->getName() << " was destroyed." << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap from ClapTrap " << this->getName() << " was copied." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "Assignment operator for FragTrap called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() > 0)
		std::cout << YELLOW << "FragTrap from ClapTrap " << this->getName() << " says: \"HIGH FIVE EVERYONE! :)\"" << RESET << std::endl;
	else
		std::cout << "Cannot high five because ClapTrap " << this->getName() << " is dead!" << std::endl;
}
