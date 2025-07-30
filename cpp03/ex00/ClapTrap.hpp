/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:40:38 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 11:46:54 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class ClapTrap
{
	private:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &copy);
		ClapTrap	&operator=(ClapTrap const &copy);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string const	&getName(void) const;
		int const			&getHitPoints(void) const;
		int const			&getEnergyPoints(void) const;
		int const			&getAttackDamage(void) const;

		void	setName(std::string const name);
		void	setHitPoints(int const hit_points);
		void	setEnergyPoints(int const energy_points);
		void	setAttackDamage(int const attack_damage);
};

#endif
