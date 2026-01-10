/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:11:47 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/08 14:56:37 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	{
		std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
		std::vector<int>	vec; //with a vector
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(2);

		try
		{
			easyfind(vec, 1); //OK because 1 is in the container
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
		std::vector<int>	vec; //with a vector
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(2);

		try
		{
			easyfind(vec, 5); //KO NotFoundException
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 3" << RESET << std::endl;
		std::vector<int>	vec; //with a vector

		try
		{
			easyfind(vec, 5); //KO EmptyContainerException
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 4" << RESET << std::endl;
		std::list<int>	lst; //with a list
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(18);

		try
		{
			easyfind(lst, 18); //OK because 18 is in the container
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 5" << RESET << std::endl;
		std::deque<int>	dq; //with a deque
		dq.push_back(10);
		dq.push_front(20);
		dq.push_back(18);

		try
		{
			easyfind(dq, 10); //OK because 10 is in the container
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	return (0);
}
