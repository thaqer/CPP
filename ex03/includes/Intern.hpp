/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:25:58 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/30 14:21:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	static AForm* createShrubbery(const std::string &target);
	static AForm* createRobotomy(const std::string &target);
	static AForm* createPresidential(const std::string &target);


public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target);
};

#endif