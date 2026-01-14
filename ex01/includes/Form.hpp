/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:56:21 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/14 21:33:31 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:
	Form();
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too low!";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif