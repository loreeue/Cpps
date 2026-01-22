/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:44:56 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/19 13:22:16 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Construct a new Pmerge copying the args into an array
 *
 * @param argc
 * @param argv
 */
PmergeMe::PmergeMe(int argc, const char* argv[])
{
	_argc = argc - 1;
	_argv = new char*[_argc + 1];
	for (int i = 0; i < _argc; ++i)
	{
		_argv[i] = new char[std::strlen(argv[i + 1]) + 1];
		std::strcpy(_argv[i], argv[i + 1]);
	}
	_argv[_argc] = NULL;
	validateArgv();
}

/**
 * @brief Construct a new Pmerge copying the args into an array
 *
 * @param copy
 */
PmergeMe::PmergeMe(const PmergeMe &copy): _argc(copy._argc)
{
	_argv = new char*[_argc + 1];
	for (int i = 0; i < _argc; ++i)
	{
		_argv[i] = new char[std::strlen(copy._argv[i]) + 1];
		std::strcpy(_argv[i], copy._argv[i]);
	}
	_argv[_argc] = NULL;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < _argc; ++i)
			delete[] _argv[i];
		delete[] _argv;

		_argc = copy._argc;
		_argv = new char*[_argc + 1];
		for (int i = 0; i < _argc; ++i)
		{
			_argv[i] = new char[std::strlen(copy._argv[i]) + 1];
			std::strcpy(_argv[i], copy._argv[i]);
		}
		_argv[_argc] = NULL;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	for (int i = 0; i < _argc; ++i)
		delete[] _argv[i];
	delete[] _argv;
}

/**
 * @brief It validates:
			- That all characters are digits
			- That the number is positive
			- That there is no overflow (INT_MAX)
 *
 */
void	PmergeMe::validateArgv()
{
	for (int i = 0; i < _argc; ++i)
	{
		std::string	arg(_argv[i]);
		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (!std::isdigit(arg[j]))
				throw WrongInputValueException(arg, " not a positive integer");
		}

		long	value = std::atol(_argv[i]);
		if (value > INT_MAX)
			throw WrongInputValueException(arg, " integer overflow");
	}
}

/**
 * @brief Insert a value in its sorted position
 *
 * @param lst
 * @param value
 */
static void	insert_list(std::list<int> &lst, int value)
{
	std::list<int>::iterator	it = lst.begin();
	while (it != lst.end() && *it < value)
		++it;
	lst.insert(it, value);
}

/**
 * @brief Generates the Jacobsthal sequence
 *
 * @param n
 * @return std::list<size_t>
 */
static std::list<size_t>	jacobsthal(size_t n)
{
	std::list<size_t>	seq;
	size_t				j0 = 0, j1 = 1;

	while (j1 < n)
	{
		seq.push_back(j1);
		size_t	next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	return (seq);
}

static void	sort_list(std::list<int> &lst)
{
	if (lst.size() <= 1) //Base case
		return ;

	std::list<int>	big, small;
	bool			has_extra = false;
	int				extra = 0;

	if (lst.size() % 2 == 1) //Impar
	{
		extra = lst.back(); //The one who is left over is kept
		lst.pop_back();
		has_extra = true;
	}

	while (!lst.empty())
	{
		int	a = lst.front();
		lst.pop_front();
		int	b = lst.front();
		lst.pop_front();

		if (a > b)
		{
			big.push_back(a);
			small.push_back(b);
		}
		else
		{
			big.push_back(b);
			small.push_back(a);
		}
	}

	sort_list(big); //Recursive

	//We insert the elements of small into big following Jacobsthal order
	std::list<size_t>					order = jacobsthal(small.size());
	for (std::list<size_t>::iterator	it = order.begin(); it != order.end(); ++it)
	{
		if (*it >= small.size())
			continue ;
		std::list<int>::iterator	sit = small.begin();
		std::advance(sit, *it);
		insert_list(big, *sit);
		small.erase(sit);
	}

	//We insert the remaining ones
	while (!small.empty())
	{
		insert_list(big, small.front());
		small.pop_front();
	}

	//We insert the extra element
	if (has_extra)
		insert_list(big, extra);

	lst = big;
}

void	PmergeMe::sortWithList()
{
	//Add the args into the list
	std::list<int>	lst;
	for (int i = 0; i < _argc; ++i)
		lst.push_back(std::atoi(_argv[i]));

	//List before sorting
	std::cout << PINK << "Before: " << RESET;
	for (std::list<int>::iterator	it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	//Initialize clock
	clock_t	start = clock();

	//Sort the list
	sort_list(lst);

	//Clock after sorting
	double	elapsed = (double)(clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	//List after sorting
	std::cout << PINK << "After: " << RESET;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << GREEN << "Time to process a range of " << lst.size()
			  << " elements with std::list : " << elapsed << " us" << RESET << std::endl;
}

static void	insert_vector(std::vector<int> &v, int value)
{
	std::vector<int>::iterator	it = v.begin();
	while (it != v.end() && *it < value)
		++it;
	v.insert(it, value);
}

static void	sort_vector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return ;

	std::vector<int>	big, small;
	bool				has_extra = false;
	int					extra = 0;

	if (v.size() % 2 == 1) //Impar
	{
		extra = v.back(); //The one who is left over is kept
		v.pop_back();
		has_extra = true;
	}

	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
		{
			big.push_back(v[i]);
			small.push_back(v[i + 1]);
		}
		else
		{
			big.push_back(v[i + 1]);
			small.push_back(v[i]);
		}
	}

	sort_vector(big); //Recursive

	//We insert the elements of small into big following Jacobsthal order
	std::list<size_t> order = jacobsthal(small.size());
	for (std::list<size_t>::iterator it = order.begin(); it != order.end(); ++it)
	{
		if (*it >= small.size())
			continue ;
		insert_vector(big, small[*it]);
		small.erase(small.begin() + *it);
	}

	//We insert the remaining ones
	for (size_t i = 0; i < small.size(); ++i)
		insert_vector(big, small[i]);

	//We insert the extra element
	if (has_extra)
		insert_vector(big, extra);

	v = big;
}

void	PmergeMe::sortWithVector()
{
	//Add the args into the vector
	std::vector<int>	v;
	for (int i = 0; i < _argc; ++i)
		v.push_back(std::atoi(_argv[i]));

	//Initialize clock
	clock_t start = clock();

	//Sort the vector
	sort_vector(v);

	//Clock after sorting
	double	elapsed = (double)(clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << GREEN << "Time to process a range of " << v.size()
			  << " elements with std::vector : " << elapsed << " us" << RESET << std::endl;
}

const char*	PmergeMe::WrongInputValueException::what() const throw()
{
	return (_message.c_str());
}
