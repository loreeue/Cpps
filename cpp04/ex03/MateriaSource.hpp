/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:58:47 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 13:41:42 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class MateriaSource: public IMateriaSource //publicly inherits from the IMateriaSource interface
{
	private:
		AMateria	*_learnInventory[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		MateriaSource	const &operator=(MateriaSource const &copy);
		~MateriaSource(void);

		//has the implementations of the IMateriaSource interface
		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const &type);
		int 				inLearnInventory(AMateria *materia);
};

# endif
