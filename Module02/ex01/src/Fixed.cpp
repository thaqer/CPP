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
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int val) : value(val << fractionalbits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : value(roundf(val * (1 << fractionalbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::toInt( void ) const
{
	return this->value >> fractionalbits;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << fractionalbits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}