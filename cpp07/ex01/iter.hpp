/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:40:18 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/07 17:30:54 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define YELLOW "\033[1;33m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>

# define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

class Test
{
	private:
		int	_i;

	public:
		Test() : _i(0) {}
		void	setI(int i) {this->_i = i;}
		int		getI() const {return (this->_i);}
};

std::ostream &operator<<(std::ostream &os, const Test &t)
{
	os << "Class (" << t.getI() << ")";
	return (os);
}

template <typename T>
void	printElement(const T &element)
{
	std::cout << "Element: " << BLUE << element << RESET << std::endl;
}

void	sumOne(int num)
{
	std::cout << "Element + 1: " << BLUE << num + 1 << RESET << std::endl;
}

//iters an array and apply a function to each element
//array -> direction of the 1st element of the array
//len -> num elements array
//func
template <typename T, typename F>
void iter(T* array, const size_t len, F func)
{
	for(size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif
