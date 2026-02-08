/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/02/08 19:36:34 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void print(T const &x)
{
	std::cout << x << " ";
}

template <typename T> void increment(T &x)
{
	x++;
}

int main(void) 
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "42"};
	
	std::cout << "Int array: ";
	::iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	std::cout << "String array: ";
	::iter(strArray, 2, print<std::string>);
	std::cout << std::endl;
	
	::iter(intArray, 5, increment<int>);
	std::cout << "After increment: ";
	::iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	return 0;
}