/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:12 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/03 13:29:16 by loruzqui         ###   ########.fr       */
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
		Fixed	&operator=(Fixed const &copy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr); //for the operator <<

#endif
