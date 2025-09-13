/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 15:53:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-12 15:53:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		std::ostringstream oss;
		oss << i;
		horde[i].setName(name + "_" + oss.str());
		++i;
	}
	return horde;
}
