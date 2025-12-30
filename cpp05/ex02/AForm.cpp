/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:11:55 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/29 16:54:59 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _is_signed(false), _grade_sign(150), _grade_execute(150)
{
}

AForm::AForm(std::string const &name, int const grade_sign, int const grade_execute): _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade_sign > 150 || grade_execute > 150)
		throw (Bureaucrat::GradeTooLowException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _is_signed(copy._is_signed), _grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{
}

AForm::~AForm(void)
{
}

AForm const	&AForm::operator=(AForm const &copy)
{
	this->_is_signed = copy._is_signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	AForm::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	str << "Name: " << form.getName() << std::endl;
	str << "isSigned: ";
	if (form.getIsSigned())
		str << "true" << std::endl;
	else
		str << "false" << std::endl;
	str << "Grade to sign: " << form.getGradeSign() << std::endl;
	str << "Grade to execute: " << form.getGradeExecute() << std::endl;
	return (str);
}
