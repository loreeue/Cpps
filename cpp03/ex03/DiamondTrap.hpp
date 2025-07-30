/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:14:36 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 13:07:46 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

/*
DiamondTrap inherits publicly from ScavTrap and FragTrap.
All public methods of ScavTrap and FragTrap will also be public methods of DiamondTrap.
*/
class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		/*
		The name is set as an attribute because it is different from the one used internally by ClapTrap (adding _clap_name)
		*/
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap	&operator=(DiamondTrap const &copy);
		~DiamondTrap(void);

		std::string const	&getName(void) const;
		void	setName(std::string const name);

		void	attack(const std::string& target);
		void whoAmI(void);
};

#endif
