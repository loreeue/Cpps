/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:36:03 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 17:02:10 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP
# define PHONEBOOK_UTILS_HPP

# include <iostream>
# include "Contact.hpp"

std::string	add_spaces(int n);
std::string	fix_width(std::string str, long unsigned max);
int			search_ui(Contact contacts[8]);

#endif
