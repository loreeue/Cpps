/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:40:44 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 12:03:23 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	{
		std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
		Array<int>	array(10);
		srand(time(NULL));
		for (unsigned int i = 0; i < array.size(); i++)
		{
			int value = rand();
			array[i] = value;
		}
		std::cout << std::endl << YELLOW << "Array values:" << RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << std::endl;

		Array<int>	copy = array;

		std::cout << std::endl << YELLOW << "Copy values:" << RESET<< std::endl;
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << std::endl;
	}

	{
		std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
		Array<std::string>	array(6);
		array[0] = "Hola";
		array[1] = "que";
		array[2] = "tal";
		array[3] = "soy";
		array[4] = "Loreto";
		array[5] = ":))";

		std::cout << std::endl << YELLOW << "Array values:" << RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << PINK << "TEST 3" << RESET << std::endl;
		Array<char>	array(6);
		array[0] = 'l';
		array[1] = 'o';
		array[2] = 'r';
		array[3] = 'e';
		array[4] = 't';
		array[5] = 'o';

		std::cout << std::endl << YELLOW << "Array values:" << RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i];
		std::cout << std::endl;

		std::cout << std::endl << YELLOW << "Trying to access to invalid positions:" << RESET<< std::endl;
		try
		{
			array[-2] = 's';
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::cout << array[6] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 4" << RESET << std::endl;

		std::cout << std::endl << YELLOW << "Exceptions:" << RESET<< std::endl;
		try
		{
			//array of size=0, if i access -> exception
			Array<char>	array(0);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}

		try
		{
			//array of size=-1, overflow
			Array<char>	array(-1);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}

		try
		{
			//array of size=100001, overflow
			Array<char>	array(100001);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}
	}

	return (0);
}
