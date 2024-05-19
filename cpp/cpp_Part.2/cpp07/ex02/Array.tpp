/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:37:12 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/19 19:06:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"
#include "color.hpp"

template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _elements(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(const Array& src) : _elements(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < src._size; i++)
		_elements[i] = src._elements[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] _elements;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		delete[] _elements;
		_size = src._size;
		_elements = new T[src._size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = src._elements[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return (RED "Index is out of bounds!" RST);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
