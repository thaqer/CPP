/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-06 08:19:05 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-06 08:19:05 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setContact()
{
    std::string input;

	while (firstname.empty())
	{
    	std::cout << "First name: ";
		std::getline(std::cin, firstname);
	}
    while (lastname.empty())
	{
    	std::cout << "Last name: ";
        std::getline(std::cin, lastname);
	}
    while (nickname.empty())
	{
    	std::cout << "Nickname: ";
        std::getline(std::cin, nickname);
	}
    while (phoneNumber.empty())
	{
		// here I can use isdigit to check each character something like this :
		//if (std::any_of(phoneNumber.begin(), phoneNumber.end(), [](char c){ return !std::isdigit(c); }))
    	std::cout << "Phone number: ";
        std::getline(std::cin, phoneNumber);
		if (phoneNumber.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Invalid phone number. Please enter digits only." << std::endl;
			phoneNumber.clear();
		}
	}
    while (darkestSecret.empty())
	{
    	std::cout << "Darkest secret: ";
        std::getline(std::cin, darkestSecret);
	}
}

void Contact::displayContact(int index) const
{
	std::cout << std::setw(10) << index << "|";
	if (firstname.length() > 10)
		std::cout << firstname.substr(0, 9) + ".|";
	else
		std::cout << std::setw(10) << firstname << "|";
	if (lastname.length() > 10)
		std::cout << lastname.substr(0, 9) + ".|";
	else
		std::cout << std::setw(10) << lastname << "|";
	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9) + ".|";
	else
		std::cout << std::setw(10) << nickname << "|";
	std::cout << std::endl;
}

void Contact::displayFullContact() const
{
	std::cout << "First name: " << firstname << std::endl;
	std::cout << "Last name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
