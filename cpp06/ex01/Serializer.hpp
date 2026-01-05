/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:37:21 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/02 18:27:08 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# define RED	"\033[1;31m"
# define BLUE	"\033[1;34m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# include <iostream>
# include <string>

typedef struct	s_data
{
	std::string	str;
}	Data;

typedef	size_t	uintptr_t;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
