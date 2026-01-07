/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:39:22 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 11:40:22 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define YELLOW "\033[1;33m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>

//swaps the values of two given parameters
//no return anything
template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

//compares the two values passed as parameters and returns the smallest one
//if they are equal, it returns the second one
template <typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

//compares the two values passed as parameters and returns the greatest one
//if they are equal, it returns the second one
template <typename T>
T	max(T &a, T &b)
{
	if (a < b)
		return (b);
	return (a);
}

#endif
