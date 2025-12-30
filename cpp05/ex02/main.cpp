/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:11:07 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/30 16:33:32 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	//Create the 3 forms and some Bureaucrats
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("marvin");
	PresidentialPardonForm pardon("student_42");
	Bureaucrat ana("Ana", 150);
	Bureaucrat silvia("Silvia", 120);
	Bureaucrat mery("Mery", 3);

	std::cout << std::endl << " --------------------- " << std::endl;

	//Try to execute forms without being signed
	{
		try
		{
			std::cout << ana << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			//Error because execute without sign
			ana.executeForm(shrubbery);
			ana.executeForm(robotomy);
			ana.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Sign form and try to execute without enough grade
	{
		try
		{
			std::cout << ana << std::endl;
			std::cout << silvia << std::endl;
			std::cout << shrubbery << std::endl;
			shrubbery.beSigned(silvia); //Good because silvia has 120 and shrubbery requires for sign 145 or less
			ana.executeForm(shrubbery); //Error because ana has 150 and shrubbery requires for execute 137 or less
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Sign forms and execute them
	{
		try
		{
			std::cout << mery << std::endl;
			robotomy.beSigned(mery); //Good because mery has 3 and robotomy requires for sign 72 or less
			pardon.beSigned(mery); //Good because mery has 3 and pardon requires for sign 25 or less
			std::cout << shrubbery << std::endl; //Silvia sign in the last test
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(shrubbery); //Good because ana has 3 and shrubbery requires for execute 137 or less
			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(robotomy); //Good because ana has 3 and robotomy requires for execute 45 or less
			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(pardon); //Good because ana has 3 and pardon requires for execute 5 or less
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Trillian");
		ShrubberyCreationForm tardon("Meg");
		std::cout << "\n";

		try
		{
			boss.signForm(robot);
			boss.executeForm(robot);
			std::cout << "\n";

			boss.signForm(pardon);
			boss.executeForm(pardon);
			std::cout << "\n";

			boss.signForm(tardon);
			boss.executeForm(tardon);
			std::cout << "\n";
		} catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	return (0);
}
