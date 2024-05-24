/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:48:54 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/24 17:03:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include "color.hpp"

class Span
{
public:
    // Public Constructors and Destructor
    Span(unsigned int N);
    Span(Span const &src);
    Span& operator=(const Span &rhs);
    ~Span();
    
    // Public Methods
    void    addNumber(int N);
    void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int     shortestSpan() const;
    int     longestSpan() const;
    
    // Execption
    class	SpanFull : public std::exception
    {
	public:
		virtual const char *what() const throw()
		{
			return (RED "The span is full !" RST);
		}
    };
    
    class NotEnoughElements : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return (RED "Not enough elements to find a span!" RST);
        }
    };

private:
    // Private members
    unsigned int        _maxSize;
    std::vector<int>    _numbers;
};

#endif