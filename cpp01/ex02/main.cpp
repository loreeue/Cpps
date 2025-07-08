/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:25:37 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/26 09:23:48 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include <iostream>
#include <string>

int main(void)
{
	//---------------- 1. Create a regular string variable stored in memory (on the stack).
	std::string string = "HI THIS IS BRAIN";

	//---------------- 2. Create a pointer to the string:
	// Pointers store memory addresses, in this case, the address of the 'string' variable.
	std::string *stringPTR = &string;

	//---------------- 3. Create a reference to the string:
	// A reference is an alias, another name for the same variable.
	std::string &stringREF = string;

	//---------------- 4. Print memory addresses:
	// Prints the memory address of the 'string' variable.
	std::cout << "The memory address of the string variable: " << &string << std::endl;

	// Prints the memory address stored in 'stringPTR', which is the same as the address of 'string'.
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;

	// Prints the memory address of 'stringREF', which is exactly the same as the address of 'string',
	// since a reference does not create a new variable, it is just another name for the same one.
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	//---------------- 5. Print values:
	// Prints the value of the 'string' variable.
	std::cout << "The value of the string variable: " << string << std::endl;

	// Prints the value pointed to by 'stringPTR', which is the value of 'string'.
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;

	// Prints the value of 'stringREF', which is exactly the same as the value of 'string'.
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
