/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:19:34 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/06 13:23:56 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(void): std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy): std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	if (this != &copy)
		std::stack<T>::operator=(copy);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}
