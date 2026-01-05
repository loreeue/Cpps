/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:07:14 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/04 18:15:49 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const std::string specials[6] = {
	"nan", "-inf", "+inf",
	"nanf", "-inff", "+inff"
};


ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool	isChar(const std::string &input)
{
	return (input.length() == 1 && !isdigit(input[0]));
}

bool	isInt(const std::string &input)
{
	size_t	i = 0;

	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]))
			return (false);
	}
	return (true);
}

bool	isDouble(const std::string &input)
{
	size_t	i = 0;
	int		counter = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return (false);
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return (false);
	}
	if (counter != 1)
			return (false);
	return (true);
}

bool	isFloat(const std::string &input)
{
	size_t	i = 0;
	int		counter = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (input[input.length() - 1] != 'f' || (input.length() == 2 && !isdigit(input[0])))
		return (false);
	if (input[0] == '+' ||input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length() - 1; j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return (false);
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return (false);
	}
	return (true);
}

type	parse(const std::string &input)
{
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isDouble(input))
		return (DOUBLE);
	if (isFloat(input))
		return (FLOAT);
	return (ERROR);
}

bool	limits(const std::string &input, type _type)
{
	if (_type == INT)
	{
		long	val = std::strtol(input.c_str(), NULL, 10);
		if (val < INT_MIN || val > INT_MAX)
			return (false);
	}
	else if (_type == DOUBLE || _type == FLOAT)
	{
		double	val = std::strtod(input.c_str(), NULL);
		if (std::isnan(val) || std::isinf(val))
			return (false);
		if (_type == FLOAT)
		{
			if (val > FLT_MAX || val < -FLT_MAX)
				return (false);
		}
		else
		{
			if (val > DBL_MAX || val < -DBL_MAX)
				return (false);
		}
	}
	return (true);
}

void	printChar(const std::string &input)
{
	char	c = input[0];

	if (!isprint(c))
		throw ScalarConverter::InvalidInputException();
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt(const std::string &input)
{
	int					nbr;
	std::stringstream	ss(input);

	ss >> nbr;
	if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << nbr << ".0f" << std::endl;
	std::cout << "double: " << nbr << ".0" << std::endl;
}

bool	isPseudoLiteral(const std::string &input, type _type)
{
	if (_type == DOUBLE)
	{
		for (int i = 0; i < 3; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << "f" << std::endl;
				std::cout << "double: " << input << std::endl;
				return (true);
			}
		}
	}
	else if (_type == FLOAT)
	{
		for (int i = 3; i < 6; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << std::endl;
				std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
				return (true);
			}
		}
	}
	return (false);
}

void	printDouble(const std::string &input, type _type)
{
	double				nbr;
	std::stringstream	ss(input);

	ss >> nbr;
	if (!isPseudoLiteral(input, _type))
	{
		if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << nbr << std::endl;
	}
}

void	printFloat(const std::string &input, type _type)
{
	float				nbr;
	std::stringstream	ss(input);

	ss >> nbr;
	if (!isPseudoLiteral(input, _type))
	{
		if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
}

void	converter(const std::string &input, type _type)
{
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
		{
			if (i < 3)
			{
				printDouble(input, _type);
				return ;
			}
			else
			{
				printFloat(input, _type);
				return ;
			}
		}
	}
	switch (_type)
	{
		case CHAR:
			printChar(input);
			break;
		case INT:
			printInt(input);
			break;
		case DOUBLE:
			printDouble(input, _type);
			break;
		case FLOAT:
			printFloat(input, _type);
			break;
		default:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	type	_type;

	if (str.empty())
		throw ScalarConverter::InvalidInputException();
	_type = parse(str);
	for (int i = 0; i < 6; i++)
	{
		if (str == specials[i])
		{
			converter(str, _type);
			return ;
		}
	}
	if (!limits(str, _type))
	{
		std::cerr << RED << "Error: Overflow detected" << RESET << std::endl;
		return ;
	}
	converter(str, _type);
}

char const	*ScalarConverter::InvalidInputException::what(void) const throw()
{
	return ("Invalid input :(");
}
