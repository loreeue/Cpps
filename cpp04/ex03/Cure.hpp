/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:57:03 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 13:35:51 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Cure: public AMateria //derivates from the abstract class materia
{
	public:
		Cure(void);
		Cure(Cure const &copy);
		Cure	const &operator=(Cure const &copy);
		~Cure(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
