/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:55:03 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/08 17:29:52 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Cat: public Animal //derivates from animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &copy);
		~Cat(void);

		Brain	&getBrain(void) const;
		void	setBrain(Brain const &brain);

		void	makeSound(void) const;
};

#endif
