/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:18:23 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/26 09:09:43 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//we create the object in the stack
//the object exists inside the function
//when the function finish -> deleted automatically
void randomChump(std::string name)
{
	Zombie	chumpZombie(name);

	chumpZombie.announce();
}
