/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:59:41 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/31 11:12:57 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iterator>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const& src) {(void)src;}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {(void)rhs; return *this; }
PmergeMe::~PmergeMe() {}

std::list<int>& PmergeMe::parseToList(const char* argv)
{
    static std::list<int> list;
    std::istringstream iss(argv);
    std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(list));
    return list;
}

std::vector<int>& PmergeMe::parseToVec(const char* argv)
{
    static std::vector<int> vec;
    std::istringstream iss(argv);
    std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(vec));
    return vec;
}
