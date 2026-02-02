/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/02 20:35:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input)
{
	double value = 0;
	
	if (input.length() == 1 && !std::isdigit(input[0]))
		value = input[0];
	else
		value = std::strtod(input.c_str(), NULL);

	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(value) << std::endl;

	if (std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}