/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/03 19:41:01 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string&input) {
	std::cout << std::fixed << std::setprecision(1);

	// Handle special pseudo-inputs: nan, +inf, -inf (and their float versions)
	if (input == "nan" ||input == "nanf" ||
		input == "+inf" ||input == "-inf" ||
		input == "+inff" ||input == "-inff") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		if (input[input.size() - 1] == 'f') {
			std::cout << "float: " <<input << "\n";
			std::cout << "double: " <<input.substr(0,input.size() - 1) << "\n";
		} else {
			std::cout << "float: " <<input << "f\n";
			std::cout << "double: " <<input << "\n";
		}
		return;
	}

	// Handle single non-digit character (e.g., 'a', '*', etc.)
	if (input.size() == 1 && !std::isdigit(input[0])) {
		char c =input[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	// Setup for number parsing
	char* endptr = NULL;
	errno = 0;

	// Try to parse as integer
	long l = std::strtol(input.c_str(), &endptr, 10);
	if (*endptr == '\0' && errno != ERANGE) {
		if (l >= 32 && l <= 126)
			std::cout << "char: '" << static_cast<char>(l) << "'\n";
		else if (l >= 0 && l <= 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << l << "\n";
		std::cout << "float: " << static_cast<float>(l) << "f\n";
		std::cout << "double: " << static_cast<double>(l) << "\n";
		return;
	}

	// Try to parse as float (ends with 'f')
	float f = std::strtof(input.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0') {
		if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'\n";
		else if (f >= 0 && f <= 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(f) << "\n";
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
		return;
	}

	// Try to parse as double
	double d = std::strtod(input.c_str(), &endptr);
	if (*endptr == '\0') {
		if (d >= 32 && d <= 126)
			std::cout << "char: '" << static_cast<char>(d) << "'\n";
		else if (d >= 0 && d <= 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(d) << "\n";
		std::cout << "float: " << static_cast<float>(d) << "f\n";
		std::cout << "double: " << d << "\n";
		return;
	}

	// Invalid input: cannot convert to any type
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}
