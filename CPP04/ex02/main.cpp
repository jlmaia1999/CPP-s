/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:33:39 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/15 17:18:16 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << "===== BRAIN TESTS =====" << std::endl;
	Brain brain;
	brain.AddIdea("I want to sleep");
	brain.AddIdea("I want to eat");
	brain.Print_idea();
	std::cout << std::endl;

	Brain brainCopy(brain);
	std::cout << "Copy brain ideas:" << std::endl;
	brainCopy.Print_idea();
	std::cout << std::endl;

	Brain brainAssigned;
	brainAssigned.AddIdea("Old idea");
	brainAssigned = brain;
	std::cout << "Assigned brain ideas:" << std::endl;
	brainAssigned.Print_idea();
	std::cout << std::endl;

	std::cout << "===== DOG TESTS =====" << std::endl;
	Dog dog;
	dog.Add_Idea("Bark");
	dog.Add_Idea("Walk");
	std::cout << "Dog initial ideas:" << std::endl;
	dog.Print_idea();
	std::cout << std::endl;

	Dog dogCopy(dog);
	dogCopy.Add_Idea("Fetch");
	std::cout << "Dog copy ideas:" << std::endl;
	dogCopy.Print_idea();
	std::cout << std::endl;

	Dog dogAssigned;
	dogAssigned.Add_Idea("Dummy");
	dogAssigned = dog;
	dogAssigned.Add_Idea("Bone");
	std::cout << "Dog assigned ideas:" << std::endl;
	dogAssigned.Print_idea();
	std::cout << std::endl;

	std::cout << "===== CAT TESTS =====" << std::endl;
	Cat cat;
	cat.Add_Idea("Nap");
	cat.Add_Idea("Hunt");
	std::cout << "Cat initial ideas:" << std::endl;
	cat.Print_idea();
	std::cout << std::endl;

	Cat catCopy(cat);
	catCopy.Add_Idea("Climb");
	std::cout << "Cat copy ideas:" << std::endl;
	catCopy.Print_idea();
	std::cout << std::endl;

	Cat catAssigned;
	catAssigned.Add_Idea("Dummy");
	catAssigned = cat;
	catAssigned.Add_Idea("Purr");
	std::cout << "Cat assigned ideas:" << std::endl;
	catAssigned.Print_idea();
	std::cout << std::endl;

	std::cout << "===== POLYMORPHISM TESTS =====" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	Dog* dogPtr = new Dog();
	Cat* catPtr = new Cat();
	dogPtr->Add_Idea("Chase");
	catPtr->Add_Idea("Sleep");
	std::cout << "Dog pointer ideas:" << std::endl;
	dogPtr->Print_idea();
	std::cout << "Cat pointer ideas:" << std::endl;
	catPtr->Print_idea();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	delete dogPtr;
	delete catPtr;

	std::cout << "===== ALL TESTS COMPLETE =====" << std::endl;
	return (0);
}