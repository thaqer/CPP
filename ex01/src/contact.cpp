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

// Reads one non-empty line into "field".
// Returns false at end of input (Ctrl+D), so the program can't loop forever.
static bool readField(const std::string &prompt, std::string &field, bool digitsOnly)
{
	field.clear();
	while (field.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return false;
		if (digitsOnly && field.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Invalid phone number. Please enter digits only." << std::endl;
			field.clear();
		}
	}
	return true;
}

// Fills a temporary contact first, so a cancelled ADD never
// overwrites the contact that is already stored in this slot.
bool Contact::setContact()
{
	Contact tmp;

	if (!readField("First name: ", tmp.firstname, false)
		|| !readField("Last name: ", tmp.lastname, false)
		|| !readField("Nickname: ", tmp.nickname, false)
		|| !readField("Phone number: ", tmp.phoneNumber, true)
		|| !readField("Darkest secret: ", tmp.darkestSecret, false))
		return false;
	*this = tmp;
	return true;
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
