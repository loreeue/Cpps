/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:13:40 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/30 13:08:05 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &copy)
{
	(void)copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern(void)
{
}

AForm*	Intern::makeForm(const std::string &name_form, const std::string &target) const
{
	const	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(const std::string&) = {createShrubbery, createRobotomy, createPardon};

	int	i = 0;
	while (i < 3 && name_form != names[i])
		i++;
	if (i < 3)
	{
		std::cout << GREEN << "Intern creates " << name_form << RESET << std::endl;
		return (creators[i](target));
	}
	std::cout << RED << "Intern couldn't create form: " << name_form << " does not exist." << RESET << std::endl;
	return (NULL);
}

AForm*	createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}
