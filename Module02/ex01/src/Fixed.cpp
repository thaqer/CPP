/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-27 16:19:27 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-12-27 16:19:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Fixed b(a);
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//a = b
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // self assigment check
	{
		this->value = other.value;
	}
	return *this;
}
// a.operator=(b)
// 'this' points to 'a'
// 'other' refers to 'b'
// Returns reference to 'a'

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Converts integer to fixed-point by shifting left 8 bits (multiply by 256)
Fixed::Fixed(const int val) : value(val << fractionalbits)
{
    std::cout << "Int constructor called" << std::endl;
}

// Converts float to fixed-point by multiplying by 256 and rounding
Fixed::Fixed(const float val) : value(roundf(val * (1 << fractionalbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

// Converts fixed-point back to integer by shifting right 8 bits (divide by 256)
int	Fixed::toInt( void ) const
{
	return this->value >> fractionalbits;
}

// Converts fixed-point back to float by dividing by 256
float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << fractionalbits);
}

// Allows printing Fixed objects with std::cout by converting to float
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}