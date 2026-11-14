/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-26 18:05:10 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-12-26 18:05:10 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.";
	std::cout << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int x = 0;
	while (x < 4 && levels[x] != level)
		x++;
	if (x < 4)
		(this->*functions[x])();
	return ;

}
