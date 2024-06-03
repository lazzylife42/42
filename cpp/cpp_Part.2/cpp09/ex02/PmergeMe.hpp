#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>

class PmergeMe
{
public:
    static std::list<int>& parseToList(const char* argv);
    static std::vector<int>& parseToVec(const char* argv);

    template <typename T>
    static T& sortContainer(T& container);

    template <typename T>
    static T& FordJohnson(T& container);

    template <typename T>
    bool comparePairs(const std::pair<T, T>& a, const std::pair<T, T>& b);

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

    template <typename T>
    static void mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container);
};

template <typename T>
T& PmergeMe::sortContainer(T& container)
{
    if (container.size() <= 10)
        insertionSort(container, container.begin(), container.end());
    else
        mergeSort(container, container.begin(), container.end());
    return container;
}

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
            pairs.push_back(std::make_pair(first, typename T::value_type()));
        }
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs<typename T::value_type>);
    mergePairs(pairs, container);
    
    return container;
}

template <typename T>
bool comparePairs(const std::pair<T, T>& a, const std::pair<T, T>& b)
{
    return std::max(a.first, a.second) < std::max(b.first, b.second);
}

template <typename T>
void PmergeMe::mergeSort(T& container, typename T::iterator left, typename T::iterator right)
{
    if (std::distance(left, right) <= 1)
        return;

    typename T::iterator middle = left;
    std::advance(middle, std::distance(left, right) / 2);

    mergeSort(container, left, middle);
    mergeSort(container, middle, right);
    merge(container, left, middle, right);
}

template <typename T>
void PmergeMe::merge(T& container, typename T::iterator left, typename T::iterator middle, typename T::iterator right)
{
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

template <typename T>
void PmergeMe::mergePairs(std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, T& container)
{
    container.clear();
    for (typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        container.push_back(std::min(it->first, it->second));
        container.push_back(std::max(it->first, it->second));
    }
}

#endif
