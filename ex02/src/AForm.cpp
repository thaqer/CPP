/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:26:18 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/28 19:22:57 by tbaniatt         ###   ########.fr       */
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

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > executeGrade)
		throw GradeTooLowException();
	action();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << form.getSignGrade()
	   << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
