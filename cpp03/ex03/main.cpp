/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 13:02:43 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
	Public virtual inheritance is used to avoid the diamond problem in multiple inheritance.

	The diamond problem occurs when two classes (ScavTrap and FragTrap) both inherit from the same base class (ClapTrap),
	and a third class (DiamondTrap) inherits from both of them. Without `virtual`, DiamondTrap would contain two separate
	copies of ClapTrap, leading to ambiguity and redundant data.

	By declaring the inheritance as `public virtual ClapTrap`, both ScavTrap and FragTrap share a single base ClapTrap instance,
	ensuring consistency and avoiding conflicts.

	Example:
		ClapTrap
		/     \
	ScavTrap   FragTrap
		\     /
		DiamondTrap   ← single ClapTrap instance (thanks to virtual)
*/

void	mew_rundown(void)
{
	DiamondTrap mew("Mew");

	mew.attack("Pikachu");
	mew.attack("Bulbasur");
	mew.attack("Squirtle");
	mew.guardGate();
	mew.highFivesGuys();
	mew.whoAmI();
}

void	umbreon_rundown(void)
{
	DiamondTrap	umbreon("Umbreon");

	while (umbreon.getHitPoints())
	{
		umbreon.takeDamage(20);
		umbreon.beRepaired(10);
	}
	umbreon.takeDamage(1);
	umbreon.guardGate();
	umbreon.highFivesGuys();
	umbreon.whoAmI();
}

int	main(void)
{
	std::cout << "\n\n🌟 A wild Mew appeared! Preparing for battle...\n\n";
	mew_rundown();
	std::cout << "\n\n🌟 A wild Umbreon appeared! Preparing for battle...\n\n";
	umbreon_rundown();
}
