/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:10:39 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:15:25 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RED	"\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <climits>

class RPN
{
	private:
		std::string	_input;
		RPN(void); //So that an rpn without an expression cannot be created

	public:
		RPN(const std::string &input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN(void);

		void		RPNCalculator();

		std::string	getInput() const;
		void		setInput(const std::string &input);

		//For specific messages
		class ErrorException: public std::exception
		{
			private:
				std::string	_message;
			public:
				ErrorException(): _message(RED "Error" RESET) {}
				ErrorException(const std::string &message): _message(RED "Error: " + message + RESET) {}
				virtual ~ErrorException() throw() {}
				virtual const char* what() const throw();
		};
};

#endif
