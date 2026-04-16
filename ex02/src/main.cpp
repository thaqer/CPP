/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/04/11 18:36:48 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main(void) 
{
	Array<int> ar1(5);
	for(size_t i = 0; i < ar1.size(); i++)
		ar1[i] = i;
	for(size_t i = 0; i < ar1.size(); i++)
		std::cout << ar1[i] << std::endl;
	try
	{
		std::cout << ar1[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}