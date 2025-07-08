/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:05:22 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/30 16:02:30 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
Reference -> Weapon& -> HumanA
	- Always has always a weapon
	- References in C++ must be initialized at object creation and cannot be null.
*/
/*
Pointer -> Weapon* -> HumanB
	- Not always has a weapon
	- If the pointer is null, it has no weapon.
	- You can change the weapon at any time with setWeapon.
*/

int	main()
{
	/*
	Scope block:
		- Anything you declare inside those braces only exists within that block.
		- At the end of the block, the variables are automatically destroyed.
	*/
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return (0);
}
