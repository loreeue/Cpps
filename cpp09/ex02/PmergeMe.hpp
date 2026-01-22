/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:45:05 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:22:53 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <list>
# include <vector>
# include <cstdlib>
# include <climits>
# include <ctime>
# include <stdexcept>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define PINK	"\033[1;35m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

class PmergeMe
{
	private:
		int		_argc;
		char**	_argv;
		PmergeMe(void);

	public:
		PmergeMe(int argc, const char* argv[]);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe(void);

		void	validateArgv();
		void	sortWithList();
		void	sortWithVector();

		//For specific messages
		class WrongInputValueException: public std::exception
		{
			private:
				std::string	_message;

			public:
				WrongInputValueException(const std::string &arg, const std::string &msg)
				{
					_message = "Error: " + arg + msg;
				}
				virtual ~WrongInputValueException() throw() {}
				virtual const char* what() const throw();
		};
};

#endif
