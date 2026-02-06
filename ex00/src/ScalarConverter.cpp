/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaer <thaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 00:46:26 by thaer            ###   ########.fr       */
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
	if (errno == ERANGE || int_value < std::numeric_limits<int>::min() || int_value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	else if (int_value < 31 || int_value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(int_value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(int_value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(int_value) << std::endl;
}

void	char_casting(std::string input)
{
	if (input[0] < 31 || input[0] > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
}

void	float_casting(std::string input)
{
	double float_value = std::strtod(input.c_str(), NULL);
	if (errno == ERANGE || float_value < -std::numeric_limits<float>::max() || float_value > std::numeric_limits<float>::max())
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		if (float_value < 31 || float_value > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(float_value) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(float_value) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(float_value) << "f" << std::endl;
}

void ScalarConverter::convert(const std::string&input)
{
	t_type type;
	
	if (input.length() == 1 && !std::isdigit(input[0]))
		type = CHAR;
	else if (input.find('.') != std::string::npos)
	{
		if (input.back() == 'f' && input.find('f') == input.length() - 1)
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