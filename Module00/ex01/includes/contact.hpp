/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-06 08:10:41 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-06 08:10:41 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>


class Contact
{
private:

	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:

	void setContact();
	void displayContact(int index) const;
	void displayFullContact() const;

};

#endif