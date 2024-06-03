/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/06/03 18:33:59 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

class PmergeMe
{
public:
    static std::list<int>& parseToList(const char* argv);
    static std::vector<int>& parseToVec(const char* argv);

    template <typename T>
    static T& FordJohnson(T& container);

    template <typename T>
    static bool comparePairs(const std::pair<typename T::value_type, typename T::value_type>& a, const std::pair<typename T::value_type, typename T::value_type>& b);

private:
    PmergeMe();
    PmergeMe(PmergeMe const& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    template <typename T>
    static void mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container);
};

template <typename T>
T& PmergeMe::FordJohnson(T& container)
{
    std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;

    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        typename T::value_type first = *it;
        ++it;

        if (it != container.end())
        {
            typename T::value_type second = *it;
            pairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            pairs.push_back(std::make_pair(first, first)); // Ensure a valid pair
        }
    }

    std::sort(pairs.begin(), pairs.end(), PmergeMe::comparePairs<typename T::value_type>);
    mergePairs(pairs, container);

    return container;
}

template <typename T>
bool PmergeMe::comparePairs(const std::pair<typename T::value_type, typename T::value_type>& a, const std::pair<typename T::value_type, typename T::value_type>& b)
{
    return std::max(a.first, a.second) < std::max(b.first, b.second);
}

template <typename T>
void PmergeMe::mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container)
{
    container.clear();
    for (typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        container.push_back(std::min(it->first, it->second));
    }
    for (typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        container.push_back(std::max(it->first, it->second));
    }

    // Since the container now has two sorted halves, we need to merge them.
    std::vector<typename T::value_type> sorted;
    typename T::iterator mid = container.begin();
    std::advance(mid, container.size() / 2);
    typename T::iterator left = container.begin();
    typename T::iterator right = mid;

    while (left != mid && right != container.end())
    {
        if (*left < *right)
        {
            sorted.push_back(*left);
            ++left;
        }
        else
        {
            sorted.push_back(*right);
            ++right;
        }
    }

    while (left != mid)
    {
        sorted.push_back(*left);
        ++left;
    }

    while (right != container.end())
    {
        sorted.push_back(*right);
        ++right;
    }

    container.assign(sorted.begin(), sorted.end());
}

#endif