/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:40:19 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 16:19:19 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_num;
		std::string	_secret;
	public:
		Contact(void);
		~Contact(void);

		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nick_name(void) const;
		std::string	get_phone_num(void) const;
		std::string	get_secret(void) const;

		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nick_name(std::string str);
		void		set_phone_num(std::string str);
		void		set_secret(std::string str);
};

#endif
