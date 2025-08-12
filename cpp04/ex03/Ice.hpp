/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:56:47 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 13:36:00 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Ice: public AMateria //derivates from the abstract class animal
{
	public:
		Ice(void);
		Ice(Ice const &copy);
		Ice	const &operator=(Ice const &copy);
		~Ice(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
