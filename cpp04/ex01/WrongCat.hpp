/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:51 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 12:48:02 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class WrongCat: public WrongAnimal //derivates from wrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string const &type);
		WrongCat(WrongCat const &copy);
		WrongCat	&operator=(WrongCat const &copy);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
