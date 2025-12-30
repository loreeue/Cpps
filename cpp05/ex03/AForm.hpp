/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:11:50 by loruzqui          #+#    #+#             */
/*   Updated: 2025/12/30 13:06:35 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_sign;
		const int			_grade_execute;

	public:
		AForm(void);
		AForm(std::string const &name, int const grade_sign, int const grade_execute);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		AForm const	&operator=(AForm const &copy);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;

		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0; //

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif
