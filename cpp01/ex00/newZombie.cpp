/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:17:25 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/26 09:08:27 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//we create the object in the heap
//the object exists outside the function
Zombie*		newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}
