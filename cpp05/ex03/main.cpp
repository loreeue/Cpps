/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:11:07 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/29 18:38:17 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		bob;
	AForm		*form;
	Bureaucrat	lore("Loreto", 50);

	std::cout << std::endl << " --------------------- " << std::endl;

	//Test how all forms are created properly execpt for the last one
	{
		try
		{
			form = bob.makeForm("robotomy request", "Alice");
			delete form;
			form = bob.makeForm("shrubbery creation", "Charlie");
			delete form;
			form = bob.makeForm("presidential pardon", "David");
			delete form;
			form = bob.makeForm("random request", "Elisa"); //Error because the form doesn't exist
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Test some Actions with available form
	{
		form = bob.makeForm("shrubbery creation", "Fred");
		form->beSigned(lore); //Good because lore has 50 and this shrubbery form requires for sign 145 or less
		lore.executeForm(*form); //Good because lore has 50 and this shrubbery form requires for execute 137 or less
		delete form;
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	{
		form = bob.makeForm("presidential pardon", "Georgia");
		lore.signForm(*form); //Error because lore has 50 and this pardon form requires for sign 25 or less
		lore.executeForm(*form); //Error because lore has 50 and this pardon form requires for execute 5 or less
		delete form;
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}
