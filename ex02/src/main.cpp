/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/28 19:58:10 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm shrubbery("home");
		
		std::cout << bob << std::endl;
		std::cout << shrubbery << std::endl;
		
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm Success ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robotomy("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robotomy << std::endl;
		
		alice.signForm(robotomy);
		alice.executeForm(robotomy);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm Success ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Grade Too Low to Sign ===" << std::endl;
	try {
		Bureaucrat lowly("Lowly", 150);
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << lowly << std::endl;
		std::cout << pardon << std::endl;
		
		lowly.signForm(pardon);
		lowly.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Grade Too Low to Execute ===" << std::endl;
	try {
		Bureaucrat signer("Signer", 20);
		Bureaucrat executor("Executor", 50);
		PresidentialPardonForm pardon("Zaphod");
		
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << pardon << std::endl;
		
		signer.signForm(pardon);
		executor.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Execute Unsigned Form ===" << std::endl;
	try {
		Bureaucrat chief("Chief", 1);
		ShrubberyCreationForm shrubbery("garden");
		
		std::cout << chief << std::endl;
		std::cout << shrubbery << std::endl;
		
		chief.executeForm(shrubbery);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Multiple Robotomy Attempts ===" << std::endl;
	try {
		Bureaucrat engineer("Engineer", 1);
		RobotomyRequestForm robot1("Target1");
		RobotomyRequestForm robot2("Target2");
		RobotomyRequestForm robot3("Target3");
		
		std::cout << engineer << std::endl;
		
		engineer.signForm(robot1);
		engineer.executeForm(robot1);
		
		engineer.signForm(robot2);
		engineer.executeForm(robot2);
		
		engineer.signForm(robot3);
		engineer.executeForm(robot3);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Copy Constructor Test ===" << std::endl;
	try {
		ShrubberyCreationForm original("original");
		ShrubberyCreationForm copy(original);
		
		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
