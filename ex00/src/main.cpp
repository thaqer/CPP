/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaer <thaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/13 23:15:03 by thaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	try 
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
		b1.incrementGrade(); // This should throw an exception
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "After decrement: " << b2 << std::endl;
		b2.decrementGrade(); // This should throw an exception
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

/*
Why use exceptions?
- Handle errors gracefully
- Separate error handling from normal code
- Custom error messages

Why try-catch in main?
- Centralized error handling
- Prevent program crashes
- Clean error reporting
*/