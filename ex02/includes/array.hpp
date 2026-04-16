/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:44:49 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/11 15:56:40 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array
{
	private:
		T *array;
		unsigned int len;
	public:
		Array(): array(NULL), len(0) {}
		Array(unsigned int n) 
		{
			len = n;
			array = new T[n];
		}
		Array(const Array &other)
		{
			len = other.len;
			array = new T[len];
			for (size_t i = 0; i < len; i++)
				array[i] = other.array[i];
		}
		T &operator[](unsigned int index)
		{
			if (index >= len)
				throw std::out_of_range("Index out of range");
			return array[index];
		}
		T &operator[](unsigned int index) const
		{
			if (index >= len)
				throw std::out_of_range("Index out of range");
			return array[index];
		}
		~Array() {delete[] array};

		unsigned int size() const;
};

#endif