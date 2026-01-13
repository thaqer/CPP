/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-02 15:06:17 by tbaniatt          #+#    #+#             */
/*   Updated: 2026-01-02 15:06:17 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	clap.attack("Scavvy");
	scav.takeDamage(5);
	scav.beRepaired(3);
	scav.attack("Clappy");
	clap.takeDamage(7);
	clap.beRepaired(4);

	return 0;
}
