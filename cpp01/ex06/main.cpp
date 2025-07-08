/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:49:58 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/27 10:23:15 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	harl_translate(char *argv)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			return (i);
	return (-1);
}

void harl_switch(char *argv, Harl & h)
{
	switch (harl_translate(argv))
	{
		case 0:
			h.complain("DEBUG");
			/* fall through */ //so that by not putting a break it does not give an error
		case 1:
			h.complain("INFO");
			/* fall through */
		case 2:
			h.complain("WARNING");
			/* fall through */
		case 3:
			h.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Harl k;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(argv[1], k);
	return (0);
}
