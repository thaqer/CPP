/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:36:11 by thaer             #+#    #+#             */
/*   Updated: 2026/11/14 22:36:11 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(void)
{
	// 1. Empty array
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// 2. new T[n]() -> every element starts at its default value
	Array<int> zeros(3);
	std::cout << "Array<int>(3): ";
	for (unsigned int i = 0; i < zeros.size(); i++)
		std::cout << zeros[i] << " ";
	std::cout << std::endl;

	// 3. Works with any type
	Array<std::string> words(2);
	words[0] = "Hello";
	words[1] = "42";
	std::cout << "Array<std::string>: " << words[0] << " " << words[1] << std::endl;

	// 4. Deep copy: changing the copy must not change the original
	Array<int> original(3);
	for (unsigned int i = 0; i < original.size(); i++)
		original[i] = i + 1;
	Array<int> copy(original);
	Array<int> assigned;
	assigned = original;
	copy[0] = 100;
	assigned[1] = 200;
	std::cout << "original: " << original[0] << " " << original[1] << " " << original[2] << std::endl;
	std::cout << "copy:     " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;
	std::cout << "assigned: " << assigned[0] << " " << assigned[1] << " " << assigned[2] << std::endl;

	// 5. Out of range access throws
	try
	{
		original[3] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "original[3]: " << e.what() << std::endl;
	}
	try
	{
		original[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "original[-2]: " << e.what() << std::endl;
	}

	// 6. Stress test (from the subject): compare with a plain C array
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	bool same = true;
	for (int i = 0; i < MAX_VAL; i++)
		if (mirror[i] != numbers[i])
			same = false;
	std::cout << "750 random values match: " << (same ? "yes" : "no") << std::endl;
	delete[] mirror;
	return 0;
}
