/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/07/18 03:45:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAXDISPLAY 42

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

class PmergeMe
{
public:

    static std::list<int> parseToList(const char* argv);
    static std::vector<int> parseToVec(const char* argv);
    static std::deque<int> parseToDeque(const char* argv);

    template <typename T>
    static T& FordJohnson(T& container);

    template <typename T>
    static bool isSorted(const T& container);

private:
    PmergeMe();
    PmergeMe(PmergeMe const& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();
    
    template <typename T>
    static void mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container);
    
    template <typename T>
    static bool comparePairs(const std::pair<typename T::value_type, typename T::value_type>& a, const std::pair<typename T::value_type, typename T::value_type>& b);
};

template <typename T>
T& PmergeMe::FordJohnson(T& container)
{
    // Vérifie si le conteneur est vide. Si oui, il retourne immédiatement.
    if (container.empty())
        return container;

    // Crée des paires d'éléments consécutifs du conteneur. Si le nombre d'éléments est impair, le dernier élément est traité séparément.
    std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
    typename T::value_type lastElement;
    bool hasOddElement = false;

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
            lastElement = first;
            hasOddElement = true;
        }
    }

    // Trie chaque paire individuellement et les trie ensuite par leur premier élément.
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs<T>);

    // Fusionne les éléments des paires triées dans le conteneur.
    mergePairs(pairs, container);

    // Ajoute le dernier élément séparé s'il existe.
    if (hasOddElement)
        container.insert(std::upper_bound(container.begin(), container.end(), lastElement), lastElement);

    return container;
}

template <typename T>
bool PmergeMe::comparePairs(const std::pair<typename T::value_type, typename T::value_type>& a, const std::pair<typename T::value_type, typename T::value_type>& b)
{
    return a.first < b.first;
}

template <typename T>
void PmergeMe::mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container)
{
    std::vector<typename T::value_type> merged;

    for (size_t i = 0; i < pairs.size(); ++i)
        merged.push_back(pairs[i].first);

    for (size_t i = 0; i < pairs.size(); ++i)
        merged.push_back(pairs[i].second);

    std::sort(merged.begin(), merged.end());

    container.clear();
    container.insert(container.end(), merged.begin(), merged.end());
}

template <typename T>
bool PmergeMe::isSorted(const T& container)
{
    if (container.empty())
        return true;

    typename T::const_iterator it = container.begin();
    typename T::const_iterator next = it;
    ++next;

    while (next != container.end())
    {
        if (*it > *next)
            return false;
        ++it;
        ++next;
    }

    return true;
}

#endif

