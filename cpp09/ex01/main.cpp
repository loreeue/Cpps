/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:10:25 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/12 19:24:55 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << YELLOW << "Error: Wrong use." << RESET << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn(argv[1]);
		rpn.RPNCalculator();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
