/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:53 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:36:19 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	mew_rundown(void)
{
	ClapTrap mew("Mew");

	mew.attack("Pikachu");
	mew.attack("Bulbasur");
	mew.attack("Squirtle");
}

void	umbreon_rundown(void)
{
	ClapTrap	umbreon("Umbreon");

	while (umbreon.getHitPoints())
	{
		umbreon.takeDamage(2);
		umbreon.beRepaired(2);
	}
	umbreon.takeDamage(1);
}

int	main(void)
{
	std::cout << "\n\n🌟 A wild Mew appeared! Preparing for battle...\n\n";
	mew_rundown();
	std::cout << "\n\n🌟 A wild Umbreon appeared! Preparing for battle...\n\n";
	umbreon_rundown();
}
