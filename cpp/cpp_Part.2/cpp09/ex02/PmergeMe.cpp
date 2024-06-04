/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:59:41 by smonte-e          #+#    #+#             */
/*   Updated: 2024/06/04 10:26:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iterator>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const& src) {(void)src;}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {(void)rhs; return *this; }
PmergeMe::~PmergeMe() {}

std::list<int> PmergeMe::parseToList(const char* argv)
{
    std::list<int> result;
    std::istringstream iss(argv);
    int number;
    while (iss >> number)
    {
        result.push_back(number);
    }
    return result;
}

std::vector<int> PmergeMe::parseToVec(const char* argv)
{
    std::vector<int> result;
    std::istringstream iss(argv);
    int number;
    while (iss >> number)
    {
        result.push_back(number);
    }
    return result;
}

std::deque<int> PmergeMe::parseToDeque(const char* argv)
{
    std::deque<int> result;
    std::istringstream iss(argv);
    int number;
    while (iss >> number)
    {
        result.push_back(number);
    }
    return result;
}