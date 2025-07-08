/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:40:44 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 17:04:03 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Utils.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "An empty phonebook for 8 contacts has been created" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "The phonebook has been destroyed" << std::endl;
}

void	Phonebook::add(void)
{
	std::string	str;

	str = "";
	if (this->_index > 7)
		std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].get_first_name() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_first_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_last_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_nick_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].set_secret(str);
			std::cout << this->_contacts[this->_index % 8].get_first_name() << " successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
		}
	}
	this->_index++;
}

void	Phonebook::print(Contact contact)
{
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.get_first_name().size())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nick_name() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

Contact	Phonebook::get_contact(int index)
{
	return (this->_contacts[index % 8]);
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!search_ui(this->_contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->_contacts[str[0] - 1 - '0'].get_first_name().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}
