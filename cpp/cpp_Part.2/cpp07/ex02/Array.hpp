/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:34:48 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/19 19:03:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include "color.hpp"

template<typename T>
class Array
{
public:
    // Public Constructors and Destructor
    Array();
    Array(unsigned int size);
    Array(Array const &src);
    Array& operator=(const Array &rhs);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    ~Array();
    // Public Methods
    unsigned int size() const;
    class OutOfBoundsException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    
private:
    // Private members
    T*              _elements;
    unsigned int    _size;
};

#endif
