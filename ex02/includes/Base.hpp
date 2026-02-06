/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:46:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 15:14:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
#define Base_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <ctime>
#include <stdint.h>

class Base
{
public:
	virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
