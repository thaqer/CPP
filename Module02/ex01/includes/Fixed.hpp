/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-27 16:18:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-12-27 16:18:49 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>


class Fixed
{
	int		value;
	static const int	fractionalbits = 8;
public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
