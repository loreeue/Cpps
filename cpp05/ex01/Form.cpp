/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:10:20 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/30 13:04:59 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _is_signed(false), _grade_sign(150), _grade_execute(150)
{
}

Form::Form(std::string const &name, int const grade_sign, int const grade_execute): _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade_sign > 150 || grade_execute > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Form::Form(Form const &copy): _name(copy._name), _is_signed(copy._is_signed), _grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{
}

Form::~Form(void)
{
}

Form const	&Form::operator=(Form const &copy)
{
	this->_is_signed = copy._is_signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	Form::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
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
