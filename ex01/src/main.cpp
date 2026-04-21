/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:58:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/21 21:21:25 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		int values[] = {1, 2, 3, 4, 5};
		std::vector<int> numbers(values, values + 5);
		Span sp2 = Span(10);
		sp2.addNumber(numbers.begin(), numbers.end());

		std::cout << "Shortest Span in sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span in sp2: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
