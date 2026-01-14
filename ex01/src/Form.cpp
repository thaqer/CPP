/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:19:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/14 21:33:31 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		// name, signGrade, and executeGrade are const and cannot be assigned
	}
	std::cout << "Form assignment operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecuteGrade() const
{
	return executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecuteGrade();
	return os;
}

