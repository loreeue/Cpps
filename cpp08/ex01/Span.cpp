/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:14:48 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/08 15:44:15 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _maxInts(0)
{
}

Span::Span(const unsigned int &n): _maxInts(n)
{
	this->_data.reserve(n);
}

Span::Span(const Span &copy): _maxInts(copy._maxInts)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_maxInts = copy._maxInts;
		this->_data.clear();
		this->_data = copy._data;
	}
	return (*this);
}

Span::~Span(void)
{
}

void	Span::addNumber(const int &n)
{
	if (this->_data.size() < this->_maxInts)
		this->_data.push_back(n);
	else
		throw ContainerFilledException();
}

//search the most short difference between 2 diferent numbers of the containers
//[3, 10, 20]
//|10 − 3| = 7
//|20 − 10| = 10
//|20 − 3| = 17
//shortestSpan = 7
long long	Span::shortestSpan() const
{
	if (this->_data.size() <= 1)
		throw EnoughElementsException();

	std::vector<int>	copy = this->_data;
	std::sort(copy.begin(), copy.end()); //algorithm STL

	long long	span = LLONG_MAX;
	for (size_t i = 1; i < copy.size(); ++i)
	{
		long long	diff = static_cast<long long>(copy[i]) - static_cast<long long>(copy[i - 1]);
		if (diff < span)
			span = diff;
	}
	return (span);
}

//search the most long difference between 2 diferent numbers of the containers
//[3, 10, 20]
//|10 − 3| = 7
//|20 − 10| = 10
//|20 − 3| = 17
//longestSpan = 17
//is the same if we do de max element - the min element |20 − 3| = 17
long long	Span::longestSpan() const
{
	if (this->_data.size() <= 1)
		throw EnoughElementsException();

	std::vector<int>::const_iterator	minIt = std::min_element(_data.begin(), _data.end()); //algorithm STL
	std::vector<int>::const_iterator	maxIt = std::max_element(_data.begin(), _data.end()); //algorithm STL

	return (static_cast<long long>(*maxIt) - static_cast<long long>(*minIt));
}

void	Span::printSpan() const
{
	std::vector<int>::const_iterator	it;
	int	i = 0;
	for (it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		std::cout << "span[" << i << "] = " << *it << std::endl;
		i++;
	}
}

const char* Span::ContainerFilledException::what() const throw()
{
	return "The container is full :(";
}

const char* Span::EnoughElementsException::what() const throw()
{
	return "Not enough elements to find a span :(";
}
