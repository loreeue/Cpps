/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:49:37 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 15:34:01 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class AAnimal
{
	protected:
		std::string	_type;
		AAnimal(void);
		AAnimal(std::string const &type);
		AAnimal(AAnimal const &copy);

	public:
		AAnimal const	&operator=(AAnimal const &copy);
		virtual ~AAnimal(void); //it is made virtual so that when using delete, the destructor of the derived class is invoked first and then that of the base class

		std::string const	&getType(void) const;
		void	setType(std::string const type);

		//the method is purely virtual: it must be redefined in subclasses
		//this makes the class abstract.
		virtual Brain 		&getBrain(void) const = 0;

		//allows you to redefine the behavior of a function in a derived class
		virtual void	makeSound(void) const = 0;
};

#endif
