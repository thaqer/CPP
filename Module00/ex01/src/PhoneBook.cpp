/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-05 13:06:59 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-05 13:06:59 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	x = 0;
	Count = 0;
}

void PhoneBook::addContact()
{
    if (Count < 8)
    {
        contact[Count].setContact();
        Count++;
    }
    else
    {
        contact[x].setContact();
        x = (x) % 8;
    }
}

void PhoneBook::searchContact() const
{
    if (Count == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "----------|----------|----------|----------|" << std::endl;

	int i = 0;
	while (i < Count)
	{
		contact[i].displayContact(i);
		i++;
	}

    std::cout << "Enter the index of the contact to view details: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= Count)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    contact[index].displayFullContact();
}
