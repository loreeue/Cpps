/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:12 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/03 13:28:03 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*
Orthodox Canonical Form:
	- Default constructor: with no args
	- Copy constructor: to create a new object as a copy of another.
	- Copy assignment operator: to assign an object to an existing one.
	- Destructor
*/
class Fixed
{
	private:
		int					_value;
		static const int	_frac;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
