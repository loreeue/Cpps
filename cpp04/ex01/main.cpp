/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:56:58 by loruzqui          #+#    #+#             */
/*   Updated: 2025/08/06 13:06:29 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

/*int	main(void)
{
	const Animal	*animals[10];
	int				i;

	i = 0;
	while (i < 10)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
	while (i)
	{
		delete animals[10 - i];
		i--;
	}
	Dog	a;
	Dog	b(a);
}*/

#define N_ANIMALS 10

int main(void)
{
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i < N_ANIMALS / 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl;
		Brain *brain;
		brain = &lotsOfAnimals[0]->getBrain();
		brain->setIdea("I want chocolate!", 0);
		brain->setIdea("Let's play football!!", 1);
		brain->setIdea("Feed me human!", 2);
		std::cout << lotsOfAnimals[0]->getBrain().getIdea(0) << std::endl;
		std::cout << lotsOfAnimals[0]->getBrain().getIdea(1) << std::endl;
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
	return (0);
}
