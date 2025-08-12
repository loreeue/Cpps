/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:41 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:16:20 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal	&operator=(WrongAnimal const &copy);
		virtual ~WrongAnimal(void); //it is made virtual so that when using delete, the destructor of the derived class is invoked first and then that of the base class

		std::string const	&getType(void) const;
		void	setType(std::string const type);

		void	makeSound(void) const; //without virtual
		//the expected result is that the WrongAnimal sound is printed, not the WrongCat sound
};

#endif
