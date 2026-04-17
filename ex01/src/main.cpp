/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:58:13 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/17 16:56:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib>
#include <ctime>

static void subjectTest()
{
	std::cout << "[Subject test]" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void exceptionTest()
{
	std::cout << "[Exception test]" << std::endl;
	try
	{
		Span tiny(1);
		tiny.addNumber(42);
		tiny.addNumber(43);
	}
	catch (const std::exception &e)
	{
		std::cout << "addNumber exception: " << e.what() << std::endl;
	}

	try
	{
		Span tiny(1);
		tiny.addNumber(42);
		std::cout << tiny.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "shortestSpan exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void bigRangeTest()
{
	std::cout << "[10,000 numbers test]" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	const unsigned int size = 15000;
	std::vector<int> values;
	values.reserve(size);
	for (unsigned int i = 0; i < size; ++i)
		values.push_back(std::rand());

	Span big(size);
	big.addNumbers(values.begin(), values.end());

	std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << big.longestSpan() << std::endl;

	try
	{
		big.addNumbers(values.begin(), values.begin() + 1);
	}
	catch (const std::exception &e)
	{
		std::cout << "range add exception: " << e.what() << std::endl;
	}
}

int main()
{
	subjectTest();
	exceptionTest();
	bigRangeTest();
	return (0);
}