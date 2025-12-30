/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:56:17 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/29 17:46:45 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling constructor with grade too high
	{
		try
		{
			Bureaucrat	lore("Lore", 0); //Error because the maximum is 1
			std::cout << GREEN << lore << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling constructor with grade too low
	{
		try
		{
			Bureaucrat	lore("Lore", 151); //Error because the minimum is 150
			std::cout << GREEN << lore << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling gradeUp
	{
		try
		{
			Bureaucrat	lore("Lore", 3);
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeUp(); //grade = 2
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeUp(); //grade = 1
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeUp(); //grade = 0 -> Error
			std::cout << GREEN << lore << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling gradeDown
	{
		try
		{
			Bureaucrat	lore("Lore", 149);
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeDown(); //grade = 150
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeDown(); //grade = 151 -> Error
			std::cout << GREEN << lore << RESET << std::endl;
			lore.gradeDown();
			std::cout << GREEN << lore << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}
