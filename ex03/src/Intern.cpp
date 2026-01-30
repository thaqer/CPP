/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:28:37 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/30 18:28:28 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*formCreators[3])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	int	i = 0;
	while (i < 3)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formCreators[i](target);
		}
		i++;
	}
	
	std::cout << "Intern cannot create form: " << name << " (unknown form type)" << std::endl;
	return NULL;
}