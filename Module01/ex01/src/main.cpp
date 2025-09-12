/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 18:27:38 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-11 18:27:38 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "Zombie");

	int i = 0;
	while (i < N)
	{
		horde[i].announce();
		++i;
	}
	delete[] horde;
	return 0;
}