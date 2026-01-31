/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:40:10 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/07 17:49:23 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	{
		std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
		std::cout << std::endl << YELLOW << "int array:" << RESET << std::endl;

		int	intArr[] = {42, 38, 1, 14, 23, 87};
		iter(intArr, ARRAY_SIZE(intArr), printElement<int>);

		std::cout << std::endl << YELLOW << "int array (+ 1):" << RESET << std::endl;
		iter(intArr, ARRAY_SIZE(intArr), sumOne);
	}

	{
		std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
		std::cout << std::endl << YELLOW << "char array:" << RESET << std::endl;

		char	charArr[] = {'a', 'b', 'c', 'd'};
		iter(charArr, ARRAY_SIZE(charArr), printElement<char>);
	}

	{
		std::cout << std::endl << PINK << "TEST 3" << RESET << std::endl;

		std::string	strArr[] = {"Hola", "que", "tal", "soy", "loretooo", ":))"};

		std::cout << std::endl << YELLOW << "string array:" << RESET << std::endl;
		iter(strArr, ARRAY_SIZE(strArr), printElement<std::string>);
	}

	{
		std::cout << std::endl << PINK << "TEST 4" << RESET << std::endl;
		std::cout << std::endl << YELLOW << "class array:" << RESET << std::endl;

		Test	testArr[3];
		for (int i = 0; i < 3; i++)
			testArr[i].setI(i + 40);
		iter(testArr, ARRAY_SIZE(testArr), printElement<Test>);
	}

	return (0);
}
