/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:46:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/06 13:01:25 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <stdint.h>

typedef struct data
{
	int	id;
	const char	*name;
} data;

class Serialize
{
private:

	Serialize();
	Serialize(const Serialize& other);
	Serialize& operator=(const Serialize& other);
	~Serialize();

public:
	static uintptr_t serialize(data* ptr);
	static data* deserialize(uintptr_t raw);
};

#endif
