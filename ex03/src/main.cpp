/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:36:18 by thaer             #+#    #+#             */
/*   Updated: 2026/01/31 18:42:15 by tbaniatt         ###   ########.fr       */
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
	try {
		Intern intern;
		Bureaucrat toto("thaqer", 1);
		AForm* form1 = intern.makeForm("presidential pardon", "presidential");
		AForm* form2 = intern.makeForm("robotomy request", "robotomy");
		AForm* form3 = intern.makeForm("shrubbery creation", "shrubbery");
		
		if (form1) {
			toto.signForm(*form1);
			toto.executeForm(*form1);
			delete form1;
		}
		if (form2) {
			toto.signForm(*form2);
			toto.executeForm(*form2);
			delete form2;
		}if (form3) {
			toto.signForm(*form3);
			toto.executeForm(*form3);
			delete form3;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
