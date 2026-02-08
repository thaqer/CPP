/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:44:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/02/08 18:34:33 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <class T> void swap(T &a , T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T> T &min(T &a , T &b)
{
	return ((a < b ) ? a : b);
}

template <class T> T &max(T &a , T &b)
{
	return ((a > b ) ? a : b);
}

#endif