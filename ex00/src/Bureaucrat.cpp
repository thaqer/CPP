/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:15:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/31 18:18:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) 
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) 
{
	if (grade < 1) 
		throw GradeTooHighException();
	else if (grade > 150) 
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat "<< Bureaucrat::getName() <<" parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) 
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other) 
	{
		this->grade = other.grade;
		std::cout << "Bureaucrat assignment operator called" << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const 
{
	return name;
}

const int& Bureaucrat::getGrade() const 
{
	return grade;
}

void Bureaucrat::incrementGrade() 
{
	if (grade <= 1) 
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (grade >= 150) 
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
