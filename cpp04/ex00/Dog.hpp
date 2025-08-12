/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:33 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/30 12:52:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Dog: public Animal //derivates from animal
{
	public:
		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &copy);
		~Dog(void);

		void	makeSound(void) const;
};

#endif
