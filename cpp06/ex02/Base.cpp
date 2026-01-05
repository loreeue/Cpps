/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:57:45 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/02 18:19:49 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base(void)
{
}

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int	r = std::rand() % 3;

	if (r == 0)
		return (new A);
	else if (r == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p)
{
	std::cout << BLUE << "Pointer identify" << RESET << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << BLUE << "Reference identify" << RESET << std::endl;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{
	}
}
