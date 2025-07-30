/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:00:05 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/21 13:02:25 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &copy);
		FragTrap	&operator=(FragTrap const &copy);
		~FragTrap(void);

		void	highFivesGuys(void);
};

#endif
