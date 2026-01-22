/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:09:01 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:14:42 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//I don't need to manually initialize std::map, it is automatically built empty
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const std::string &file)
{
	loadDatabase(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): _database(copy._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_database = copy._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

/**
 * @brief Load the CSV into a std::map to have the dates sorted and be able to search efficiently
 *
 * @param filename
 */
void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	//Try opening database (csv)
	std::ifstream	file(filename.c_str());
	if (!file)
		throw FailOpenFileException();

	std::string	line;
	std::getline(file, line); //First line -> header

	while (std::getline(file, line)) //Rest of lines -> separated by commas
	{
		std::istringstream	iss(line);
		std::string			date, valueStr;

		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr)) //Malformed lines
			continue ;
		double	value = atof(valueStr.c_str());
		_database[date] = value;
	}
}

/**
 * @brief Verify that the first line is exactly: date | value
 *
 * @param line
 * @return true
 * @return false
 */
static bool	checkHeader(const std::string &line)
{
	return (line == "date | value");
}

/**
 * @brief Verify that a string contains only digits
 *
 * @param str
 * @return true
 * @return false
 */
static bool	isDigitString(const std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

/**
 * @brief It validates:
			- YYYY-MM-DD format
			- That year, month, and day are numbers
			- Month between 1 and 12
			- Day valid depending on the month
			- Leap years (bisiesto)
 *
 * @param date
 * @return true
 * @return false
 */
static bool	validateDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);

	if (!isDigitString(date.substr(0, 4)) ||
		!isDigitString(date.substr(5, 2)) ||
		!isDigitString(date.substr(8, 2)))
		return (false);

	int	y = atoi(date.substr(0, 4).c_str());
	int	m = atoi(date.substr(5, 2).c_str());
	int	d = atoi(date.substr(8, 2).c_str());

	if (m < 1 || m > 12 || d < 1 || d > 31)
		return (false);

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//Year bisiesto
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		daysInMonth[1] = 29;

	if (d > daysInMonth[m - 1])
		return (false);

	return (true);
}

/**
 * @brief Analyze and validate a line from the input.csv file
 *
 * @param line
 * @param date
 * @param value
 * @return true
 * @return false
 */
static bool	parseLine(const std::string &line, std::string &date, double &value)
{
	std::string	delimiter = " | ";

	//Search the delimiter
	size_t		pos = line.find(delimiter);
	if (pos == std::string::npos)
		return (false);

	//Extract the date
	date = line.substr(0, pos);
	std::string	valueStr = line.substr(pos + delimiter.length());

	char	*end;
	value = strtod(valueStr.c_str(), &end);

	if (*end != '\0')
		return (false);

	//Validate the date
	return (validateDate(date));
}

/**
 * @brief Process the entire input.csv file, line by line, and calculate the Bitcoin value
 *
 * @param filename
 */
void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	//Try opening the input file
	std::ifstream	file(filename.c_str());
	if (!file)
		throw FailOpenFileException();

	std::string	line;

	//Extract the first line -> header
	std::getline(file, line);
	if (!checkHeader(line))
		throw WrongHeaderFileException();

	//Rest of the lines
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		std::string	date;
		double		value;
		double		result;

		if (!parseLine(line, date, value))
		{
			std::cerr << YELLOW << "Error: bad input => " << line << RESET << std::endl;
			continue ;
		}

		if (value < 0)
		{
			std::cerr << YELLOW << "Error: not a positive number." << RESET << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << YELLOW << "Error: too large number." << RESET << std::endl;
			continue ;
		}

		//Search the first date >=
		std::map<std::string, double>::const_iterator	it = _database.lower_bound(date);
		//Date does not exist → nearest earlier date
		if (it != _database.begin() && (it == _database.end() || it->first > date))
			--it;

		result = value * it->second;
		std::cout << date << " => "
				<< value
				<< " = "
				<< result
				<< std::endl;
	}
}

const char*	BitcoinExchange::FailOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char*	BitcoinExchange::WrongHeaderFileException::what() const throw()
{
	return "Error: wrong input header.";
}
