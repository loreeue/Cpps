/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:55:03 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/30 12:51:00 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Cat: public Animal //derivates from animal
{
	public:
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &copy);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
