/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:57:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/16 20:59:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int> _numbers;

public:
	Span(unsigned int n);
	~Span();

	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();

private:
	Span();
};

#endif