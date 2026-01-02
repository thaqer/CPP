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
}

//Fixed b(a);
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

//Fixed a;
//a = b;
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int val) : value(val << fractionalbits)
{
}

Fixed::Fixed(const float val) : value(roundf(val * (1 << fractionalbits)))
{
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

bool Fixed::operator>(const Fixed &other) const { return this->value > other.value; }
bool Fixed::operator<(const Fixed &other) const { return this->value < other.value; }
bool Fixed::operator>=(const Fixed &other) const { return this->value >= other.value; }
bool Fixed::operator<=(const Fixed &other) const { return this->value <= other.value; }
bool Fixed::operator==(const Fixed &other) const { return this->value == other.value; }
bool Fixed::operator!=(const Fixed &other) const { return this->value != other.value; }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed &Fixed::operator++() // Prefix increment
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) // Postfix increment
{
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed &Fixed::operator--() // Prefix decrement
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) // Postfix decrement
{
	Fixed temp(*this);
	this->value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }