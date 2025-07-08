/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:25:37 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/26 09:13:44 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N = 3;

	horde = zombieHorde(N, "Horde");
 	for (int i = 0; i < N; i++)
	{
		std::cout << "Index " << i << ": ";
		horde[i].announce();
	}

	delete[] horde; //for leaks when we use new
	return (0);
}
