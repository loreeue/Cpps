/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:25:37 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/26 09:06:36 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*newZombie1;

	newZombie1 = newZombie("prueba");
	newZombie1->announce();
	randomChump("random");
	delete newZombie1; //no leaks when we use new
	return (0);
}
