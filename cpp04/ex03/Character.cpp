/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:57:56 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/28 17:07:51 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("(null)"), _inventory()
{
	std::cout << GREEN << "Character was created with default constructor." << RESET << std::endl;
}

Character::Character(std::string const &name): _name(name), _inventory()
{
	std::cout << GREEN << "Character " << this->_name << " was created." << RESET << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i <= 3; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}

	std::cout << RED << "Character " << this->_name << " was destroyed." << RESET << std::endl;
}

Character::Character(Character const &copy): ICharacter(copy), _inventory()
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i];
	}
	std::cout << "Character " << copy.getName() << " was copied." << std::endl;
}

Character	const &Character::operator=(const Character &copy)
{
	this->_name = copy.getName();
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(const std::string &name)
{
	this->_name = name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_inventory[i] == NULL)
		{
			if (this->inInventory(m))
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			std::cout << "Materia " << this->_inventory[i]->getType() << " equipped to " << this->_name << "'s inventory at index " << i << std::endl;
			return ;
		}
	}
	if (m)
		std::cout << "Cannot equip materia, " << this->_name << "'s inventory is full!" << std::endl;
	else
		std::cout << "Cannot equip invalid materia" << std::endl;
	if (!this->inInventory(m))
		delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << "Unequipped " << this->_inventory[idx]->getType() << " from " << this->_name << "'s inventory at index " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Cannot unequip materia, invalid index " << idx << std::endl;
	else
		std::cout << "Cannot unequip materia, index " << idx << " is empty!" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << "Cannot use materia, invalid index " << idx << std::endl;
	else
		std::cout << "Cannot use materia, index " << idx << " is empty!" << std::endl;
}

int Character::inInventory(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return (1);
	}
	return (0);
}
