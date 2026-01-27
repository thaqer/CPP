/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:26:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/27 20:27:36 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
	  signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		// name, signGrade, and executeGrade are const and cannot be assigned
	}
	std::cout << "AForm Copy assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

const