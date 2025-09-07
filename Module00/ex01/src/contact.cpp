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

void Contact::setContact() {
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, firstname);
    std::cout << "Last name: ";
    std::getline(std::cin, lastname);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);
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
