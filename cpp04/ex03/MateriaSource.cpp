/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:58:40 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/28 17:09:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _learnInventory()
{
	std::cout << GREEN << "Materiasource was created with default constructor." << RESET << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
	std::cout << RED << "MateriaSource was destroyed" << RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy): IMateriaSource(copy), _learnInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._learnInventory[i])
			this->_learnInventory[i] = copy._learnInventory[i];
	}
	std::cout << GREEN << "MateriaSource was copied" << RESET << std::endl;
}

MateriaSource	const &MateriaSource::operator=(const MateriaSource &copy)
{
	(void)copy;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia && this->_learnInventory[i] == NULL)
		{
			if (this->inLearnInventory(materia))
				this->_learnInventory[i] = materia;
			else
				this->_learnInventory[i] = materia;
			std::cout << "Materia " << this->_learnInventory[i]->getType() << " learned at index " << i << std::endl;
			return ;
		}
	}
	if (materia)
		std::cout << "Cannot learn materia, inventory for MateriaSource is full!" << std::endl;
	else
		std::cout << "Cannot learn invalid materia" << std::endl;
	if (!this->inLearnInventory(materia))
		delete materia;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid!" << std::endl;
	return (0);
}

int MateriaSource::inLearnInventory(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] == materia)
			return (1);
	}
	return (0);
}
