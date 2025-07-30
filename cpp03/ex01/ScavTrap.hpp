/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:48:39 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 12:51:41 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

/*
ScavTrap inherits publicly from ClapTrap.
All public methods of ClapTrap will also be public methods of ScavTrap.
*/
class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &copy);
		ScavTrap	&operator=(ScavTrap const &copy);
		~ScavTrap(void);

		void	guardGate(void);
};

#endif
