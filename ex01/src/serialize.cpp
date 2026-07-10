/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:26:52 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 13:03:08 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

Serialize::Serialize() {}
Serialize::Serialize(const Serialize&) {}
Serialize& Serialize::operator=(const Serialize&) { return *this; }
Serialize::~Serialize() {}

uintptr_t Serialize::serialize(data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<data*>(raw);
}