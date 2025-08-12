/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:58:03 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 13:34:16 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Character: public ICharacter //publicly inherits from the ICharacter interface
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &copy);
		Character	const &operator=(Character const &copy);
		~Character(void);

		std::string const	&getName(void) const;
		void	setName(std::string const &name);

		//has the implementations of the ICharacter interface
		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
		int 			inInventory(AMateria *m);
};

#endif
