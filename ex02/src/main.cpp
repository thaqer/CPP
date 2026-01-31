/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/31 18:36:26 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	try {
		Bureaucrat toto("thaqer", 1);
		ShrubberyCreationForm shrubbery("tree");
		RobotomyRequestForm robotomy("ttt");
		PresidentialPardonForm pardon("boss");
		
		toto.signForm(shrubbery);
		toto.executeForm(shrubbery);
		
		toto.signForm(robotomy);
		toto.executeForm(robotomy);
		
		toto.signForm(pardon);
		toto.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
