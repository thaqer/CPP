/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:35:59 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/11/14 22:35:59 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>

template <class T>
Array<T>::Array() : array(NULL), len(0)
{
}

// new T[n]() value-initializes every element (0 for int, "" for string)
template <class T>
Array<T>::Array(unsigned int n) : array(NULL), len(n)
{
	if (n > 0)
		array = new T[n]();
}

// Deep copy: allocate our own buffer and copy each element
template <class T>
Array<T>::Array(const Array &other) : array(NULL), len(other.len)
{
	if (len > 0)
	{
		array = new T[len]();
		for (unsigned int i = 0; i < len; i++)
			array[i] = other.array[i];
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T *copy = NULL;
		if (other.len > 0)
		{
			copy = new T[other.len]();
			for (unsigned int i = 0; i < other.len; i++)
				copy[i] = other.array[i];
		}
		delete[] array;
		array = copy;
		len = other.len;
	}
	return *this;
}

template <class T>
Array<T>::~Array()
{
	delete[] array;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::out_of_range("Array: index out of bounds");
	return array[index];
}

template <class T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw std::out_of_range("Array: index out of bounds");
	return array[index];
}

template <class T>
unsigned int Array<T>::size() const
{
	return len;
}

#endif
