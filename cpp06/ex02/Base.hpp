/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:57:37 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/03 13:54:40 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"
# define PINK	"\033[1;35m"

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base(void);
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
