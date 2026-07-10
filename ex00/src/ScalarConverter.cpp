/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/03/23 17:59:42 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

namespace
{
bool	isSingleCharLiteral(const std::string& input)
{
	return (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])));
}

bool	isPseudoLiteral(const std::string& input)
{
	return (input == "nan" || input == "nanf"
		|| input == "+inf" || input == "-inf" || input == "inf"
		|| input == "+inff" || input == "-inff" || input == "inff");
}

bool	isDigitsOnly(const std::string& input, size_t start, size_t end)
{
	if (start >= end)
		return false;
	for (size_t i = start; i < end; ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool	isIntLiteral(const std::string& input)
{
	size_t i = 0;
	if (input.empty())
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	return isDigitsOnly(input, i, input.length());
}

bool	isDoubleLiteral(const std::string& input)
{
	size_t i = 0;
	size_t dotPos;

	if (input.empty())
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	dotPos = input.find('.', i);
	if (dotPos == std::string::npos)
		return false;
	if (!isDigitsOnly(input, i, dotPos) && dotPos == i)
		return false;
	if (dotPos + 1 >= input.length())
		return false;
	if (!isDigitsOnly(input, dotPos + 1, input.length()))
		return false;
	return true;
}

bool	isFloatLiteral(const std::string& input)
{
	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return false;
	return isDoubleLiteral(input.substr(0, input.length() - 1));
}

std::string	formatFloat(float value)
{
	std::ostringstream oss;
	if (value == static_cast<float>(static_cast<int>(value)))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << std::setprecision(std::numeric_limits<float>::digits10) << value;
	return oss.str();
}

std::string	formatDouble(double value)
{
	std::ostringstream oss;
	if (value == static_cast<double>(static_cast<long>(value)))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << std::setprecision(std::numeric_limits<double>::digits10) << value;
	return oss.str();
}

void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	printFloat(double value)
{
	if (std::isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
		return;
	}
	if (value > std::numeric_limits<float>::max()
		|| value < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	std::cout << "float: " << formatFloat(static_cast<float>(value)) << "f" << std::endl;
}

void	printDouble(double value)
{
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
		return;
	}
	std::cout << "double: " << formatDouble(value) << std::endl;
}

void	printAllFromValue(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
}

void ScalarConverter::convert(const std::string&input)
{
	char	*end;
	long	intValue;
	double	value;

	if (input.empty())
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}

	if (isSingleCharLiteral(input))
	{
		printAllFromValue(static_cast<double>(input[0]));
		return;
	}

	if (isPseudoLiteral(input))
	{
		if (input[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else if (input.find("nan") != std::string::npos)
			value = std::numeric_limits<double>::quiet_NaN();
		else
			value = std::numeric_limits<double>::infinity();
		printAllFromValue(value);
		return;
 	}

	if (isIntLiteral(input))
	{
		errno = 0;
		intValue = std::strtol(input.c_str(), &end, 10);
		if (errno == ERANGE || *end != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		printAllFromValue(static_cast<double>(intValue));
		return;
	}

	if (isFloatLiteral(input))
	{
		errno = 0;
		value = std::strtod(input.c_str(), &end);
		if (errno == ERANGE || *end != 'f' || *(end + 1) != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		printAllFromValue(value);
		return;
	}

	if (isDoubleLiteral(input))
	{
		errno = 0;
		value = std::strtod(input.c_str(), &end);
		if (errno == ERANGE || *end != '\0')
		{
			std::cout << "Error: invalid input" << std::endl;
			return;
		}
		printAllFromValue(value);
		return;
	}

	std::cout << "Error: invalid input" << std::endl;
	return;
}