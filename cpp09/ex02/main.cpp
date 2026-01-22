/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:44:45 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:21:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	check_args(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		std::cerr << YELLOW << "Error: Wrong usage" << RESET << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i)
	{
		for (size_t j = 0; j < std::string(argv[i]).length(); ++j)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cerr << YELLOW << "Error: '" << argv[i]
						  << "' not a positive int" << RESET << std::endl;
				return (1);
			}
		}
		long	nbr = atol(argv[i]);
		if (nbr > INT_MAX)
		{
			std::cerr << YELLOW << "Error: '" << argv[i]
					  << "' int overflow" << RESET << std::endl;
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char const **argv)
{
	if (check_args(argc, argv))
		return (1);

	try
	{
		PmergeMe	pm(argc, argv);

		pm.sortWithList();
		pm.sortWithVector();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
