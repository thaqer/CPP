/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaer <thaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:45:27 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/13 23:11:05 by thaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	const int& getGrade() const;

	void incrementGrade();
	void decrementGrade();

	//internal Exception Classes to print error messages
	//it just a error message class
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif