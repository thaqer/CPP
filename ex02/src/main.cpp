/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/02/21 15:18:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	
	Base *a = generate();
	Base *b = generate();
	Base *c = generate();

	std::cout << "Identifying pointers:" << std::endl;
	identify(a);
	identify(b);
	identify(c);

	std::cout << "Identifying references:" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;
	
	return 0;
}