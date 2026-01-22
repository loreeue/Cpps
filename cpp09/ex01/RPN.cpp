/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:10:34 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:15:44 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const std::string &input): _input(input)
{
}

RPN::RPN(const RPN &copy): _input(copy._input)
{
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		this->_input = copy._input;
	return (*this);
}

RPN::~RPN(void)
{
}

void	RPN::RPNCalculator()
{
	//I use std::stack because Reverse Polish Notation is evaluated with a stack: operands are stacked and operators consume the last two values ​​entered
	std::stack<int>		tokens; //Container
	std::stringstream	ss(this->_input); //Separate the expression with spaces
	std::string			item; //Each token

	while (ss >> item) //For every token
	{
		if (item.length() != 1) //No "12" or "++"
			throw ErrorException();

		char	c = item[0];
		if (std::isdigit(c)) //Is a number
		{
			tokens.push(c - '0'); //Push in the stack
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') //Is a operator
		{
			if (tokens.size() < 2)
				throw ErrorException();

			int	b = tokens.top(); //Second operand
			tokens.pop();
			int	a = tokens.top(); //First operand
			tokens.pop();

			//Push the result in the stack
			if (c == '+')
				tokens.push(a + b);
			else if (c == '-')
				tokens.push(a - b);
			else if (c == '*')
				tokens.push(a * b);
			else
			{
				if (b == 0)
					throw ErrorException("division by zero");
				tokens.push(a / b);
			}
		}
		else
			throw ErrorException();
	}

	if (tokens.size() != 1)
		throw ErrorException();

	std::cout << tokens.top() << std::endl;
}

std::string	RPN::getInput() const
{
	return (this->_input);
}

void	RPN::setInput(const std::string &input)
{
	this->_input = input;
}

const char*	RPN::ErrorException::what() const throw()
{
	return ((_message).c_str());
}
