/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:35:56 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/25 18:40:54 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		std::string	get_name(void) const;
		void		set_name(std::string str);

		void		announce();
};

Zombie	*zombieHorde(int N, std::string name);

#endif
