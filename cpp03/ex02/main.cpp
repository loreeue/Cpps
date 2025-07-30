/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:36:03 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	mew_rundown(void)
{
	FragTrap mew("Mew");

	mew.attack("Pikachu");
	mew.attack("Bulbasur");
	mew.attack("Squirtle");
	mew.highFivesGuys();
}

void	umbreon_rundown(void)
{
	FragTrap	umbreon("Umbreon");

	while (umbreon.getHitPoints())
	{
		umbreon.takeDamage(20);
		umbreon.beRepaired(10);
	}
	umbreon.takeDamage(1);
	umbreon.highFivesGuys();
}

int	main(void)
{
	std::cout << "\n\n🌟 A wild Mew appeared! Preparing for battle...\n\n";
	mew_rundown();
	std::cout << "\n\n🌟 A wild Umbreon appeared! Preparing for battle...\n\n";
	umbreon_rundown();
}
