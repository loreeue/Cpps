/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:19:10 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/08 17:23:53 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	{
		std::cout << std::endl << PINK << "TEST 1" << RESET << std::endl;
		MutantStack<int>	mstack;

		mstack.push(5); //[5]
		mstack.push(17); //[17, 5]

		std::cout << YELLOW << "top value in stack: " << mstack.top() << RESET << std::endl; //show the last inserted -> 17

		mstack.pop(); //remove the last inserted -> 17

		std::cout << YELLOW << "size of stack: " << mstack.size() << RESET << std::endl;

		mstack.push(3); //[3, 5]
		mstack.push(5); //[5, 3, 5]
		mstack.push(737); //[737, 5, 3, 5]
		mstack.push(0); //[0, 737, 5, 3, 5]

		MutantStack<int>::iterator	it = mstack.begin(); //the first one who enters -> 5
		MutantStack<int>::iterator	ite = mstack.end(); //the last one who enters -> 0

		int	i = 0;
		std::cout << std::endl << YELLOW << "mstack values:" << RESET << std::endl;

		//---------------from the first one who enters to the last one who enters
		while (it != ite)
		{
			std::cout << "value at " << i++ << " position: " << *it << std::endl;
			++it;
		}

		std::stack<int>	s(mstack); //copy the stack in another stack
		i = 1;
		std::cout << std::endl << YELLOW << "s values:" << RESET << std::endl;

		//---------------from the top to the bottom
		while (!s.empty())
		{
			std::cout << "value at " << s.size() - i << " position: " << s.top() << std::endl;
			s.pop(); //remove the first element
		}
	}

	{
		std::cout << std::endl << PINK << "TEST 2" << RESET << std::endl;
		MutantStack<int>	mstack;
		std::list<int>		lst;

		mstack.push(5); //[5]
		mstack.push(17); //[17, 5]
		lst.push_back(5); //[5]
		lst.push_back(17); //[5, 17]

		std::cout << YELLOW << "top value in mstack: " << mstack.top() << RESET << std::endl;
		std::cout << YELLOW << "back value in list: " << lst.back() << RESET << std::endl;

		mstack.pop(); //remove the first element -> 17
		lst.pop_back(); //remove the last element -> 17

		std::cout << YELLOW << "size of mstack: " << mstack.size() << RESET << std::endl;
		std::cout << YELLOW << "size of list: " << lst.size() << RESET << std::endl;

		mstack.push(3); //[3, 5]
		mstack.push(5); //[5, 3, 5]
		mstack.push(737); //[737, 5, 3, 5]
		mstack.push(0); //[0, 737, 5, 3, 5]
		lst.push_back(3); //[5, 3]
		lst.push_back(5); //[5, 3, 5]
		lst.push_back(737); //[5, 3, 5, 737]
		lst.push_back(0); //[5, 3, 5, 737, 0]

		MutantStack<int>::iterator	mstack_it = mstack.begin(); //the first one who enters -> 5
		MutantStack<int>::iterator	mstack_ite = mstack.end(); //the last one who enters -> 0

		int	i = 0;
		std::cout << std::endl << YELLOW << "mstack values:" << RESET << std::endl;

		//---------------from the first one who enters to the last one who enters
		while (mstack_it != mstack_ite)
		{
			std::cout << "mstack value at " << i++ << " position: " << *mstack_it << std::endl;
			++mstack_it;
		}

		std::list<int>::iterator	lst_it = lst.begin(); //the first one who enters -> 5
		std::list<int>::iterator	lst_ite = lst.end(); //the last one who enters -> 0

		i = 0;
		std::cout << YELLOW << std::endl << "lst values:" << RESET << std::endl;

		//---------------from the first one who enters to the last one who enters
		while (lst_it != lst_ite)
		{
			std::cout << "lst value at " << i++ << " position: " << *lst_it << std::endl;
			++lst_it;
		}
	}

	return (0);
}
