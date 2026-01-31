/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:35:03 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/31 17:40:16 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to create file");
	
	file << "        *        " << std::endl;
	file << "       ***       " << std::endl;
	file << "      *****      " << std::endl;
	file << "     *******     " << std::endl;
	file << "    *********    " << std::endl;
	file << "   ***********   " << std::endl;
	file << "  *************  " << std::endl;
	file << "       |||       " << std::endl;
	file << "       |||       " << std::endl;
	file << std::endl;
	file.close();
	std::cout << "Shrubbery has been created at " << target << "_shrubbery" << std::endl;
}
