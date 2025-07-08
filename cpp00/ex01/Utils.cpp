/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui < >                               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:35:55 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 17:01:22 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

/*
To align the content in the table columns when the text does not fill the 10 characters,
and to have everything justified to the right.
*/
std::string	add_spaces(int n)
{
	std::string	str;

	while (n)
	{
		str.append(" ");
		n--;
	}
	return (str);
}

/*
So that all fields in the table have exactly the same width

Function resize:
If n is less than the current size, trim the string.
If n is greater, add null characters (\0).
*/
std::string	fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	search_ui(Contact contacts[8])
{
	char		c;
	int			i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_first_name().size() && ++i)
		{
			str = c;
			str = fix_width(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1  - '0'].get_first_name(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_last_name(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].get_nick_name(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}
