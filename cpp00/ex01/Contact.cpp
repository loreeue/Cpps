/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:40:07 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 16:41:52 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nick_name(void) const
{
	return (this->_nick_name);
}

std::string	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nick_name(std::string str)
{
	this->_nick_name = str;
}

void	Contact::set_phone_num(std::string str)
{
	this->_phone_num = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}
