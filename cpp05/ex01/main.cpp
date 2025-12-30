/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:14:51 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/29 18:00:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << " --------------------- " << std::endl;

	//Create a form with grade too high
	{
		try
		{
			Form form0("Form0", 0, 5); //Error because the maximum is 1
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Create form and sign it without exceptions
	{
		try
		{
			Bureaucrat lore("Lore", 15);
			Form form1("Form1", 20, 45);
			std::cout << lore << std::endl;
			std::cout << form1 << std::endl; //Form without sign
			lore.signForm(form1); //Good because 15 <= 20
			std::cout << form1 <<  std::endl; //Form after sign
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Create form and try to sign it but the grade is not enough
	{
		try
		{
			Bureaucrat lore("Lore", 35);
			Form form2("form2", 20, 45);
			std::cout << lore << std::endl;
			std::cout  << form2 << std::endl; //Form without sign
			lore.signForm(form2); //Error because 35 NO <= 20
			std::cout  << form2 << std::endl; //Form after sign
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}
