/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaer <thaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:46:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 00:25:15 by thaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>


typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

class ScalarConverter
{
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	static void convert(const std::string& input);
};

#endif
