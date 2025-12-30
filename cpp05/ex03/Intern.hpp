/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:13:34 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/30 13:07:25 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);
		~Intern(void);

		AForm*	makeForm(const std::string &name_form, const std::string &target) const;
};

AForm*	createShrubbery(const std::string &target);
AForm*	createRobotomy(const std::string &target);
AForm*	createPardon(const std::string &target);

#endif
