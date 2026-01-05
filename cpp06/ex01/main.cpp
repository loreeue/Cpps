/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:37:02 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/02 17:51:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	serialized;
	Data		*deserialized;

	data.str = "Hola!";
	deserialized = NULL;

	std::cout << std::endl << BLUE << "\t-- POINTER COMPARISON --" << RESET << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "Pointers are equal" << RESET << std::endl;
	else
		std::cout << RED << "Pointers are different" << RESET << std::endl;

	std::cout << std::endl << BLUE << "\t-- ORIGINAL DATA --" << RESET << std::endl;
	std::cout << "Pointer: " << &data << std::endl;
	std::cout << "String : " << data.str << std::endl;

	std::cout << std::endl << BLUE << "\t-- SERIALIZATION --" << RESET << std::endl;
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;

	std::cout << std::endl << BLUE << "\t-- DESERIALIZATION --" << RESET << std::endl;
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Pointer: " << deserialized << std::endl;
	std::cout << "String : " << deserialized->str << std::endl;

	std::cout << std::endl << BLUE << "\t-- POINTER COMPARISON --" << RESET << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "Pointers are equal" << RESET << std::endl;
	else
		std::cout << RED << "Pointers are different" << RESET << std::endl;

	return (0);
}
