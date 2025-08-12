/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:42:36 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 16:27:05 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << GREEN << "Brain created with default constructor." << RESET << std::endl;
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain destroyed." << RESET << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copied." << std::endl;
	*this = copy;
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	return (*this);
}

std::string const	&Brain::getIdea(int const &index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

void	Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}
