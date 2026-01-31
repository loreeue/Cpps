/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:15:18 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/07 17:20:56 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class	Awesome
{
	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}
		Awesome &operator= (Awesome & a) {_n = a._n; return (*this);}
		bool	operator==(Awesome const &rhs) const {return (this->_n == rhs._n);}
		bool	operator!=(Awesome const &rhs) const{return (this->_n != rhs._n);}
		bool	operator>(Awesome const &rhs) const {return (this->_n > rhs._n);}
		bool	operator<(Awesome const &rhs) const {return (this->_n < rhs._n);}
		bool	operator>=(Awesome const &rhs) const {return (this->_n >= rhs._n);}
		bool	operator<=(Awesome const &rhs) const {return (this->_n <= rhs._n);}
		int		get_n() const {return (_n);}
	private:
		int	_n;
};

std::ostream	&operator<<(std::ostream &o, const Awesome &a) {o << a.get_n(); return o;}

int	main(void)
{
	Awesome	a(2), b(4);
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
	return (0);
}
