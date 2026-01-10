/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:19:28 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 13:33:46 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define YELLOW "\033[1;33m"
# define PINK	"\033[1;35m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>
# include <ctime>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:

	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack<T> &operator=(const MutantStack<T> &copy);
		~MutantStack(void);

		typedef typename	std::stack<T>::container_type::iterator iterator;
		typedef typename	std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename	std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename	std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator				begin() {return this->c.begin(); }
		iterator				end() {return this->c.end(); }

		const_iterator			begin() const { return this->c.begin(); }
		const_iterator			end() const { return this->c.end(); }

		reverse_iterator		rbegin() { return this->c.rbegin(); }
		reverse_iterator		rend() { return this->c.rend(); }

		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }
};

#include "MutantStack.tpp"

#endif
