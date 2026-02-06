/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/02/06 15:12:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

int main(void)
{
	data myData;
	myData.id = 42;
	myData.name = "Thaer";

	std::cout << "=== Before Serialization ===" << std::endl;
	std::cout << "Address: " << &myData << std::endl;
	std::cout << "ID: " << myData.id << std::endl;
	std::cout << "Name: " << myData.name << std::endl;

	uintptr_t raw = Serialize::serialize(&myData);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "Raw value: " << raw << std::endl;

	data *ptr = Serialize::deserialize(raw);
	std::cout << "\n=== After Deserialization ===" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "ID: " << ptr->id << std::endl;
	std::cout << "Name: " << ptr->name << std::endl;

	std::cout << "\n=== Test Result ===" << std::endl;
	if (ptr == &myData)
		std::cout << "SUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "FAILURE: Pointers don't match!" << std::endl;

	return 0;
}