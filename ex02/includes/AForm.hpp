/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:08:03 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/01/25 18:45:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
};

#endif