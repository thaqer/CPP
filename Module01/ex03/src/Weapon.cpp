/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-16 18:46:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-16 18:46:12 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
