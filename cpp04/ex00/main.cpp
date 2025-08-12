/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:56:58 by loruzqui          #+#    #+#             */
/*   Updated: 2025/07/24 12:36:43 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal*	animal = new Animal();
		const Animal*	dog1 = new Dog();
		const Animal*	cat1 = new Cat();

		std::cout << dog1->getType() << std::endl;
		std::cout << cat1->getType() << std::endl;

		dog1->makeSound();
		cat1->makeSound();
		animal->makeSound();

		std::cout << std::endl << "Prueba de copia de Dog:" << std::endl;
		Dog original;
		Dog copia(original);
		std::cout << "Original: " << original.getType() << std::endl << "Copia:    " << copia.getType() << std::endl;

		delete animal;
		delete dog1;
		delete cat1;
	}
	{
		const WrongAnimal*	wrong_animal = new WrongAnimal();
		const WrongAnimal*	cat1 = new WrongCat();
		const WrongAnimal*	cat2 = new WrongCat();

		std::cout << cat1->getType() << std::endl;
		std::cout << cat2->getType() << std::endl;

		cat1->makeSound();
		cat2->makeSound();
		wrong_animal->makeSound();

		std::cout << std::endl << "Prueba de copia de Cat:" << std::endl;
		WrongCat original;
		WrongCat copia(original);
		std::cout << "Original: " << original.getType() << std::endl << "Copia:    " << copia.getType() << std::endl;

		delete wrong_animal;
		delete cat1;
		delete cat2;
	}

	return (0);
}
