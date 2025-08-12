/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:42:42 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 15:59:53 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(std::string const &type);
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &copy);
		~Brain(void);

		std::string const	&getIdea(int const &index) const;
		void	setIdea(std::string const &idea, int const &index);
};

#endif
