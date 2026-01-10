/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:12:04 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 12:42:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <list>
# include <deque>

template <typename T>
void	easyfind(const T &cont, const int &n);

class EmptyContainerException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class NotFoundException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

# include "easyfind.tpp"

#endif
