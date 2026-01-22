/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:09:07 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 14:04:59 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED	"\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <fstream>
# include <climits>
# include <map>
# include <cmath>
# include <sstream>
# include <stdexcept>

# define DATA_CSV "data.csv"

class BitcoinExchange
{
	private:
		/*
			Stores date-value pairs
			Automatically sorted by key
			Enables efficient searches (O(log n))
			Allows me to easily find the nearest lower date using lower_bound
		*/
		std::map<std::string, double> _database; //Container

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &databaseFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		void	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename) const;

		class FailOpenFileException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class WrongHeaderFileException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
