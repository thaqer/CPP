/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/02 20:40:57 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& input)
{
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

static bool isPseudoLiteral(const std::string& input)
{
	return (input == "nan" || input == "nanf" || 
			input == "+inf" || input == "+inff" || 
			input == "-inf" || input == "-inff");
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		std::cerr << "Error: empty input" << std::endl;
		return;
	}

	double value;
	
	// Handle character literal
	if (isChar(input))
	{
		value = static_cast<double>(input[1]);
	}
	// Handle pseudo literals
	else if (isPseudoLiteral(input))
	{
		if (input == "nan" || input == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inf" || input == "+inff")
			value = std::numeric_limits<double>::infinity();
		else // -inf or -inff
			value = -std::numeric_limits<double>::infinity();
	}
	// Handle numeric literals
	else
	{
		char* endPtr = NULL;
		errno = 0;
		value = std::strtod(input.c_str(), &endPtr);
		
		// Check for conversion errors
		if (errno == ERANGE)
		{
			std::cerr << "Error: value out of range" << std::endl;
			return;
		}
		
		// Check if the entire string was converted (ignoring trailing 'f' for floats)
		if (endPtr == input.c_str() || (*endPtr != '\0' && *endPtr != 'f') || 
			(*endPtr == 'f' && *(endPtr + 1) != '\0'))
		{
			std::cerr << "Error: invalid input" << std::endl;
			return;
		}
	}
	
	// Print all conversions
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
