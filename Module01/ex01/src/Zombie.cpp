/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 18:28:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-11 18:28:13 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName)
{
	name = newName;
}