/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:49:37 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/30 12:50:02 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &copy);
		virtual ~Animal(void); //it is made virtual so that when using delete, the destructor of the derived class is invoked first and then that of the base class

		std::string const	&getType(void) const;
		void	setType(std::string const type);

		//allows you to redefine the behavior of a function in a derived class
		virtual void	makeSound(void) const;
};

#endif
