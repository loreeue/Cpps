/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:56:18 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/08 17:33:32 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		AMateria	const &operator=(AMateria const &copy);
		virtual ~AMateria(void); //it is made virtual so that when using delete, the destructor of the derived class is invoked first and then that of the base class

		std::string const	&getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif
