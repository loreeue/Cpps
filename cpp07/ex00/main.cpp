/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:39:08 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 11:42:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main( void )
{
	int	a = 2;
	int	b = 3;

	std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
	std::cout << std::endl << YELLOW << "with ints:" << RESET << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	//comparison of the ASCII number of the first distinct character in both strings
	std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
	std::cout << std::endl << YELLOW << "with strings:" << RESET << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}
