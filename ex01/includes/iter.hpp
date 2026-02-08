/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:44:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/08 18:49:37 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class A, class B> void iter(A* str, size_t len, B fun)
{
	size_t x = 0;

	while (x < len)
	{
		fun(str[x]);
		x++;
	}
}

#endif