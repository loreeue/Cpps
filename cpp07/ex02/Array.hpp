/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:40:54 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/07 17:50:29 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define YELLOW "\033[1;33m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdexcept>

# define MAX_SIZE 100000

template <typename T>
class Array
{
	private:
		T*				_ptr;
		unsigned int	_size;

	public:
		Array(void);
		Array(const unsigned int &n);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array(void);

		T		&operator[](unsigned int i);
		const T	&operator[](unsigned int i) const;
		unsigned int	size() const;

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

# include "Array.tpp"

#endif
