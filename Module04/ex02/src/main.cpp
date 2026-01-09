/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-02 15:06:17 by tbaniatt          #+#    #+#             */
/*   Updated: 2026-01-02 15:06:17 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// Array of animals
	const int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << "\n--- Animals sounds ---" << std::endl;
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	// Deep copy test
	std::cout << "\n--- Deep copy test ---" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love bones!");
	Dog dog2(dog1);
	dog1.getBrain()->setIdea(0, "Changed idea!");
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	// Cleanup
	std::cout << "\n--- Deleting animals ---" << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}