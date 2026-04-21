/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:58:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/17 17:13:16 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : max(n){}
Span::~Span(){}
Span::Span(const Span &other) : max(other.max), num(other.num){}


Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		max = other.max;
		num = other.num;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (num.size() >= max)
		throw std::runtime_error("Span is full");
	num.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (num.size() < 2)
		throw std::runtime_error("Not enough numbers to compute span");

	std::vector<int> sorted(num);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(static_cast<long long>(sorted[1]) - sorted[0]);
	for (std::vector<int>::size_type i = 1; i < sorted.size() - 1; ++i)
	{
		unsigned int current = static_cast<unsigned int>(
			static_cast<long long>(sorted[i + 1]) - sorted[i]);
		if (current < minSpan)
			minSpan = current;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const
{
	if (num.size() < 2)
		throw std::runtime_error("Not enough numbers to compute span");

	int minValue = *std::min_element(num.begin(), num.end());
	int maxValue = *std::max_element(num.begin(), num.end());
	return (static_cast<unsigned int>(static_cast<long long>(maxValue) - minValue));
}
