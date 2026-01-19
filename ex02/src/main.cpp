/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/14 21:38:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	std::cout << "=== Test 1: Valid Form Creation ===" << std::endl;
	try {
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Invalid Form (Grade Too High) ===" << std::endl;
	try {
		Form form2("Bad Form", 0, 25);
		std::cout << form2 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Invalid Form (Grade Too Low) ===" << std::endl;
	try {
		Form form3("Bad Form", 151, 25);
		std::cout << form3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat Signs Form Successfully ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 30);
		Form form4("Report", 50, 25);
		std::cout << bob << std::endl;
		std::cout << form4 << std::endl;
		bob.signForm(form4);
		std::cout << form4 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat Grade Too Low to Sign ===" << std::endl;
	try {
		Bureaucrat joe("Joe", 100);
		Form form5("Important Doc", 50, 25);
		std::cout << joe << std::endl;
		std::cout << form5 << std::endl;
		joe.signForm(form5);
		std::cout << form5 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Signing Already Signed Form ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		Form form6("Contract", 10, 5);
		std::cout << alice << std::endl;
		alice.signForm(form6);
		alice.signForm(form6);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}