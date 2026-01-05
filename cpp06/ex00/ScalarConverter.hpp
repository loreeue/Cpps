/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:07:20 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/04 18:13:27 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define RED	"\033[1;31m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <climits> //INT_MIN, INT_MAX
# include <cfloat> //FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
# include <cmath> //std::isnan(), std::isinf()
# include <sstream> //stringstream
# include <iomanip> //std::fixed, std::setprecision
# include <cstdlib> //strtod, strtol
# include <exception>

extern const	std::string specials[6];

enum type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	ERROR
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter(void);

	public:
		static void	convert(const std::string &str); //static -> is a function of the class, no of the objects

		class InvalidInputException: public	std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
