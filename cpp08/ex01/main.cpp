/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:14:32 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/09 15:24:51 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	{
		try
		{
			std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
			Span	sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << std::endl << YELLOW << "print span values" << RESET << std::endl;
			sp.printSpan();

			std::cout << std::endl << YELLOW << "try shortest and logest" << RESET << std::endl;
			std::cout << sp.shortestSpan() << std::endl; //9 - 11 = 2
			std::cout << sp.longestSpan() << std::endl; //11 - 3 = 14
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << '\n';
		}
	}

	{
		try
		{
			std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
			Span	sp = Span(1);

			sp.addNumber(6);
			sp.addNumber(3); //Error because is span(1) -> ContainerFilledException
			sp.addNumber(17);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			std::cout << std::endl << PINK << "TEST 3" << RESET << std::endl;
			Span	sp = Span(0);

			std::cout << sp.shortestSpan() << std::endl; //Error because is span(0) -> EnoughElementsException
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			std::cout << std::endl << PINK << "TEST 4" << RESET << std::endl;
			Span	sp = Span(1);

			sp.addNumber(6);

			std::cout << sp.shortestSpan() << std::endl; //Error because you cannot calculate span with 1 number
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			std::cout << std::endl << PINK << "TEST 5" << RESET << std::endl;
			Span	sp = Span(10000); //Span too large

			std::cout << std::endl << YELLOW << "create and fill values vector with random ints" << RESET << std::endl;
			std::vector<int> values(10000);
			std::srand(time(0));
			for (size_t i = 0; i < values.capacity(); ++i)
			{
				values[i] = std::rand();
			}

			std::cout << std::endl << YELLOW << "add values from values vector to sp span using iterators" RESET << std::endl;
			sp.addRange(values.begin(), values.end()); //Copy all numbers from the values ​​vector into sp using iterators
			//sp.printSpan();

			std::cout << std::endl << YELLOW << "shortest and longest span" << RESET << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	return (0);
}
