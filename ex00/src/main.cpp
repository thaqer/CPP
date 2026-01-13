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

int main()
{
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trapster");

	clap1.attack("Trapster");
	clap2.takeDamage(5);
	clap2.beRepaired(3);
	clap2.attack("Clappy");
	clap1.takeDamage(7);
	clap1.beRepaired(4);

	return 0;
}