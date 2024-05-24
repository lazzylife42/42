/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:56:34 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/24 17:03:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Span.hpp"

// Constructor & Destructor

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &src) : _maxSize(src._maxSize), _numbers(src._numbers) {}

Span& Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

// Member Func

void Span::addNumber(int N)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFull();
    _numbers.push_back(N);    
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw SpanFull();
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughElements();
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
    {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughElements();

    int minElem = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElem = *std::max_element(_numbers.begin(), _numbers.end());

    return maxElem - minElem;
}
