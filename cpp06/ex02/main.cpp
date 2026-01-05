/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:56:54 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/02 18:22:45 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main(void)
{
	{
		std::cout << PINK << "Test 1:" << RESET << std::endl;
		A	*a = new A();
		B	*b = new B();
		C	*c = new C();

		identify(a);
		identify(b);
		identify(c);
		identify(NULL);

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}

	{
		std::cout << PINK << "Test 2:" << RESET << std::endl;
		Base	*base;

		base = generate();

		identify(base);
		identify(*base);

		delete base;
	}

	return (0);
}
