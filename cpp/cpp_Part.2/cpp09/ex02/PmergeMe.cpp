/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:59:41 by smonte-e          #+#    #+#             */
/*   Updated: 2024/06/03 23:53:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iterator>

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
