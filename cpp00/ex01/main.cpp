/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:41:51 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 16:22:28 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook 	pb1;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb1.add();
		else if (str == "SEARCH")
			pb1.search();
		if (std::cin.eof()) //if ctrlD -> \n
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
