/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:38:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/31 11:14:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

class PmergeMe
{
public:
    static std::list<int>& parseToList(const char* argv);
    static std::vector<int>& parseToVec(const char* argv);

    template <typename T>
    static T& sortContainer(T& container);

private:
    PmergeMe();
    PmergeMe(PmergeMe const& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    template <typename T>
    static void mergeSort(T& container, typename T::iterator left, typename T::iterator right);
    
    template <typename T>
    static void merge(T& container, typename T::iterator left, typename T::iterator middle, typename T::iterator right);

    template <typename T>
    static void insertionSort(T& container, typename T::iterator left, typename T::iterator right);
};

template <typename T>
T& PmergeMe::sortContainer(T& container)
{
    if (container.size() <= 10)
    {
        insertionSort(container, container.begin(), container.end());
    }
    else
    {
        mergeSort(container, container.begin(), container.end());
    }
    return container;
}

template <typename T>
void PmergeMe::mergeSort(T& container, typename T::iterator left, typename T::iterator right)
{
    if (std::distance(left, right) > 1)
    {
        typename T::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);

        mergeSort(container, left, middle);
        mergeSort(container, middle, right);
        merge(container, left, middle, right);
    }
}

template <typename T>
void PmergeMe::merge(T& container, typename T::iterator left, typename T::iterator middle, typename T::iterator right)
{
    (void)container;
    T leftHalf(left, middle);
    T rightHalf(middle, right);

    typename T::iterator leftIt = leftHalf.begin();
    typename T::iterator rightIt = rightHalf.begin();
    typename T::iterator it = left;

    while (leftIt != leftHalf.end() && rightIt != rightHalf.end())
    {
        if (*leftIt < *rightIt)
        {
            *it = *leftIt;
            ++leftIt;
        }
        else
        {
            *it = *rightIt;
            ++rightIt;
        }
        ++it;
    }

    while (leftIt != leftHalf.end())
    {
        *it = *leftIt;
        ++leftIt;
        ++it;
    }

    while (rightIt != rightHalf.end())
    {
        *it = *rightIt;
        ++rightIt;
        ++it;
    }
}

template <typename T>
void PmergeMe::insertionSort(T& container, typename T::iterator left, typename T::iterator right)
{
    (void)container;
    
    for (typename T::iterator it = left; it != right; ++it)
    {
        typename T::value_type key = *it;
        typename T::iterator j = it;
        while (j != left && key < *(--j))
        {
            typename T::iterator next = j;
            ++next;
            *next = *j;
        }
        typename T::iterator next = j;
        ++next;
        *next = key;
    }
}

#endif