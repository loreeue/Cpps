/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:14:41 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/09 15:25:18 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RED	"\033[1;31m"
# define YELLOW "\033[1;33m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <limits.h>

class Span
{
	private:
		std::vector<int>	_data;
		std::size_t			_maxInts;

	public:
		Span(void);
		Span(const unsigned int &n);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span(void);

		void		addNumber(const int &n);
		long long	shortestSpan() const;
		long long	longestSpan() const;

		template <typename It>
		void	addRange(It begin, It end);

		void	printSpan() const;

		class ContainerFilledException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class EnoughElementsException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

template <typename T>
void Span::addRange(T begin, T end)
{
	for (T it = begin; it != end; ++it)
	{
		if (_data.size() >= _maxInts)
			throw ContainerFilledException();
		_data.push_back(*it);
	}
}

#endif
