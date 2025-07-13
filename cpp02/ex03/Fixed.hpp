/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:12 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/06 18:27:53 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_frac;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		Fixed	&operator=(Fixed const &copy);
		Fixed	operator+(Fixed const &copy) const;
		Fixed	operator-(Fixed const &copy) const;
		Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;

		bool	operator>(Fixed const &copy) const;
		bool	operator<(Fixed const &copy) const;
		bool	operator>=(Fixed const &copy) const;
		bool	operator<=(Fixed const &copy) const;
		bool	operator==(Fixed const &copy) const;
		bool	operator!=(Fixed const &copy) const;

		Fixed	&operator++(void); //returns a reference (the same object)
		Fixed	&operator--(void);
		Fixed	operator++(int value); //returns a copy
		Fixed	operator--(int value);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static const Fixed	&min(Fixed const &first, Fixed const &second);
		static const Fixed	&max(Fixed const &first, Fixed const &second);

		static Fixed		&min(Fixed &first, Fixed &second);
		static Fixed		&max(Fixed &first, Fixed &second);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr); //for the operator <<

#endif
