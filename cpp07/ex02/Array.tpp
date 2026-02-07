/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:41:05 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/31 13:25:23 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _ptr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(const unsigned int &n)
{
	if (n > MAX_SIZE)
		throw std::length_error("Array size too large");
	this->_ptr = (new T[n]());
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &other) : _ptr(NULL), _size(0)
{
	*this = other;
}

//with deep copy -> eserving new memory and copying the elements one by one, so that the resulting objects are completely independent
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_ptr;
		this->_size = other.size();
		this->_ptr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_ptr[i] = other._ptr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (_ptr)
		delete[] this->_ptr;
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	else
		return (this->_ptr[n]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	else
		return (this->_ptr[n]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}
