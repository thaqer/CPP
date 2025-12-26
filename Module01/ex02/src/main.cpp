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

#include <iostream>
#include <string>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string &nameREF = name;
	std::string *namePTR = &name;

	std::cout << &name << std::endl;
	std::cout << namePTR << std::endl;
	std::cout << &nameREF << std::endl;

	std::cout << name << std::endl;
	std::cout << *namePTR << std::endl;
	std::cout << nameREF << std::endl;

	return 0;
}
