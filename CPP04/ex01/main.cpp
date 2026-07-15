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
	std::cout << "===== TESTING BRAIN CLASS =====" << std::endl;
	std::cout << std::endl;

	// Test 1: Brain constructor and AddIdea
	std::cout << "--- Test 1: Brain Constructor and AddIdea ---" << std::endl;
	Brain brain1;
	brain1.AddIdea("I love bones");
	brain1.AddIdea("Squirrel!");
	brain1.AddIdea("Chase the ball");
	std::cout << "Brain 1 ideas:" << std::endl;
	brain1.Print_idea();
	std::cout << std::endl;

	// Test 2: Brain copy constructor
	std::cout << "--- Test 2: Brain Copy Constructor ---" << std::endl;
	Brain brain2(brain1);
	std::cout << "Brain 2 ideas (copied from brain1):" << std::endl;
	brain2.Print_idea();
	std::cout << std::endl;

	// Test 3: Brain assignment operator
	std::cout << "--- Test 3: Brain Assignment Operator ---" << std::endl;
	Brain brain3;
	brain3.AddIdea("Original idea");
	std::cout << "Brain 3 before assignment:" << std::endl;
	brain3.Print_idea();
	brain3 = brain1;
	std::cout << "Brain 3 after assignment from brain1:" << std::endl;
	brain3.Print_idea();
	std::cout << std::endl;
	std::cout << "===== TESTING DOG CLASS WITH BRAIN =====" << std::endl;
	std::cout << std::endl;

	// Test 4: Dog constructor and Add_Idea
	std::cout << "--- Test 4: Dog Constructor and Add_Idea ---" << std::endl;
	Dog dog1;
	dog1.Add_Idea("Woof woof");
	dog1.Add_Idea("Time to eat");
	dog1.Add_Idea("Play fetch");
	std::cout << "Dog 1 ideas:" << std::endl;
	dog1.Print_idea();
	std::cout << std::endl;

	// Test 5: Dog makeSound (polymorphism)
	std::cout << "--- Test 5: Dog makeSound ---" << std::endl;
	dog1.makeSound();
	std::cout << std::endl;

	// Test 6: Dog copy constructor
	std::cout << "--- Test 6: Dog Copy Constructor ---" << std::endl;
	Dog dog2(dog1);
	std::cout << "Dog 2 ideas (copied from dog1):" << std::endl;
	dog2.Print_idea();
	std::cout << std::endl;

	// Test 7: Dog assignment operator
	std::cout << "--- Test 7: Dog Assignment Operator ---" << std::endl;
	Dog dog3;
	dog3.Add_Idea("Dummy idea");
	std::cout << "Dog 3 before assignment:" << std::endl;
	dog3.Print_idea();
	dog3 = dog1;
	std::cout << "Dog 3 after assignment from dog1:" << std::endl;
	dog3.Print_idea();
	std::cout << std::endl;
	return 0;

	std::cout << "===== TESTING CAT CLASS WITH BRAIN =====" << std::endl;
	std::cout << std::endl;
	

	// Test 8: Cat constructor and Add_Idea
	std::cout << "--- Test 8: Cat Constructor and Add_Idea ---" << std::endl;
	Cat cat1;
	cat1.Add_Idea("Nap time");
	cat1.Add_Idea("Hunt the mouse");
	cat1.Add_Idea("Ignore humans");
	std::cout << "Cat 1 ideas:" << std::endl;
	cat1.Print_idea();
	std::cout << std::endl;
	

	// Test 9: Cat makeSound (polymorphism)
	std::cout << "--- Test 9: Cat makeSound ---" << std::endl;
	cat1.makeSound();
	std::cout << std::endl;

	// Test 10: Cat copy constructor
	std::cout << "--- Test 10: Cat Copy Constructor ---" << std::endl;
	Cat cat2(cat1);
	std::cout << "Cat 2 ideas (copied from cat1):" << std::endl;
	cat2.Print_idea();
	std::cout << std::endl;

	// Test 11: Cat assignment operator
	std::cout << "--- Test 11: Cat Assignment Operator ---" << std::endl;
	Cat cat3;
	cat3.Add_Idea("Original cat idea");
	std::cout << "Cat 3 before assignment:" << std::endl;
	cat3.Print_idea();
	cat3 = cat1;
	std::cout << "Cat 3 after assignment from cat1:" << std::endl;
	cat3.Print_idea();
	std::cout << std::endl;

	std::cout << "===== TESTING POLYMORPHISM WITH ANIMAL POINTERS =====" << std::endl;
	std::cout << std::endl;


	// Test 13: Adding ideas to polymorphic objects through Dragon and Cat methods
	std::cout << "--- Test 13: Adding More Ideas ---" << std::endl;
	dog1.Add_Idea("More bones");
	cat1.Add_Idea("More fish");
	std::cout << "Dog 1 updated ideas:" << std::endl;
	dog1.Print_idea();
	std::cout << "Cat 1 updated ideas:" << std::endl;
	cat1.Print_idea();
	std::cout << std::endl;

	std::cout << "===== TEST COMPLETE =====" << std::endl;
	std::cout << "Destructors will be called as objects go out of scope:" << std::endl;

	return (0);
}