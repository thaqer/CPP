/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:57:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/17 17:12:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <iterator>

class Span
{
private:
	unsigned int	max;
	std::vector<int> num;

public:
	Span(unsigned int n);
	~Span();

	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int number);
	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end)
	{
		std::vector<int> values(begin, end);
		if (num.size() + values.size() > _maxSize)
			throw std::runtime_error("Span is full");
		num.insert(num.end(), values.begin(), values.end());
	}
	unsigned int shortestSpan();
	unsigned int longestSpan();

private:
	Span();
};

#endif