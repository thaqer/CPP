/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/30 18:05:11 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
	std::cout << "=== Test 1: Intern creates valid forms ===" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form1;
		AForm* form2;
		AForm* form3;
		
		form1 = someRandomIntern.makeForm("shrubbery creation", "home");
		form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		form3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
		
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2)
		{
			std::cout << *form2 << std::endl;
			delete form2;
		}
		if (form3)
		{
			std::cout << *form3 << std::endl;
			delete form3;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Intern with unknown form ===" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("unknown form", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation failed (returned NULL)" << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Using Intern-created form with Bureaucrat ===" << std::endl;
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* form = intern.makeForm("presidential pardon", "Criminal");
		
		if (form)
		{
			std::cout << boss << std::endl;
			std::cout << *form << std::endl;
			
			boss.signForm(*form);
			boss.executeForm(*form);
			
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Multiple forms by same Intern ===" << std::endl;
	try {
		Intern intern;
		Bureaucrat highRank("HighRank", 1);
		
		AForm* shrub = intern.makeForm("shrubbery creation", "garden");
		AForm* robot = intern.makeForm("robotomy request", "Target");
		
		if (shrub)
		{
			highRank.signForm(*shrub);
			highRank.executeForm(*shrub);
			delete shrub;
		}
		
		if (robot)
		{
			highRank.signForm(*robot);
			highRank.executeForm(*robot);
			delete robot;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Intern copy constructor ===" << std::endl;
	try {
		Intern intern1;
		Intern intern2(intern1);
		
		AForm* form1 = intern1.makeForm("robotomy request", "R2D2");
		AForm* form2 = intern2.makeForm("shrubbery creation", "park");
		
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2)
		{
			std::cout << *form2 << std::endl;
			delete form2;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
