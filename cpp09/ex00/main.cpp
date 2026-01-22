/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:08:44 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 08:56:42 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	check_args(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << YELLOW << "Error: Wrong use." << RESET << std::endl;
		return (1);
	}

	//Try opening input file
	std::ifstream	infile;
	infile.open(argv[1]);
	if (!infile)
	{
		std::cerr << YELLOW << "Error: could not open file." << RESET << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	if (check_args(argc, argv) == (1))
		return (1);

	try
	{
		BitcoinExchange	btc(DATA_CSV);
		btc.processInputFile(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}
