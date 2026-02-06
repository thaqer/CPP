/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 12:48:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}


void	int_casting(std::string input)
{
	long int_value = std::strtol(input.c_str(), NULL, 10);
	
	// Check char range
	if (int_value < 0 || int_value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (int_value < 32 || int_value == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(int_value) << "'" << std::endl;
	
	// Check int range
	if (int_value < std::numeric_limits<int>::min() || int_value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(int_value) << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(int_value) << std::endl;
}

void	char_casting(std::string input)
{
	if (input[0] < 32 || input[0] > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

void	float_casting(std::string input)
{
	double float_value = std::strtod(input.c_str(), NULL);
	if (float_value < 0 || float_value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (float_value < 32 || float_value == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(float_value) << "'" << std::endl;

	if (float_value < std::numeric_limits<int>::min() || float_value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(float_value) << std::endl;

	if (float_value > std::numeric_limits<float>::max() || float_value < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(float_value) << "f" << std::endl;
	}
	std::cout << "double: " << static_cast<double>(float_value) << std::endl;
}

void	double_casting(std::string input)
{
	double double_value = std::strtod(input.c_str(), NULL);
	if (double_value < 0 || double_value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (double_value < 32 || double_value == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(double_value) << "'" << std::endl;

	if (double_value < std::numeric_limits<int>::min() || double_value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(double_value) << std::endl;

	if (double_value > std::numeric_limits<float>::max() || double_value < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(double_value) << "f" << std::endl;
	}
	std::cout << "double: " << double_value << std::endl;
}

bool isValidInput(const std::string& input)
{
	// Single char is valid
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	
	// Check for valid number format
	size_t i = 0;
	bool hasDecimal = false;
	bool hasDigit = false;
	
	// Optional sign
	if (input[i] == '+' || input[i] == '-')
		i++;
	
	// Digits and optional decimal point
	while (i < input.length())
	{
		if (std::isdigit(input[i]))
			hasDigit = true;
		else if (input[i] == '.' && !hasDecimal)
			hasDecimal = true;
		else if (input[i] == 'f' && i == input.length() - 1 && hasDecimal)
			break; // Valid float suffix
		else
			return false;
		i++;
	}
	return hasDigit;
}

void ScalarConverter::convert(const std::string&input)
{
	t_type type;
	double value;

	if (input.empty())
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}
	
	value = std::strtod(input.c_str(), NULL);
	if (std::isinf(value) || std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
		return;
	}

	if (!isValidInput(input))
	{
		std::cout << "Error: invalid input" << std::endl;
		return;
	} 

	if (input.length() == 1 && !std::isdigit(input[0]))
		type = CHAR;
	else if (input.find('.') != std::string::npos)
	{
		if (input[input.length() - 1] == 'f' && input.find('f') == input.length() - 1)
			type = FLOAT;
		else
			type = DOUBLE;
	}
	else
		type = INT;
	switch (type)
	{
		case INT:
			int_casting(input);
			break;
		case CHAR:
			char_casting(input);
			break;
		case FLOAT:
			float_casting(input);
			break;
		case DOUBLE:
			double_casting(input);
			break;
	}
}