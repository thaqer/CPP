/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-05 13:08:16 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-05 13:08:16 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "contact.hpp"

class PhoneBook
{
private:

    Contact contact[8];
    int Count;
    int x;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;
};

#endif