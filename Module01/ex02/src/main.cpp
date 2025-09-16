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
	std::string &nameRef = name;
	std::string *namePtr = &name;

	std::cout << &name << std::endl;
	std::cout << namePtr << std::endl;
	std::cout << &nameRef << std::endl;

	std::cout << name << std::endl;
	std::cout << *namePtr << std::endl;
	std::cout << nameRef << std::endl;

	return 0;
}
