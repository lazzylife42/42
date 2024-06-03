/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:20:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/06/04 00:33:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PmergeMe.hpp"
#include "color.hpp"

// ./PmergeMe "$(jot -r 3000 1 1000 | tr '\n' ' ')"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Usage: ./PmergeMe <\"numbers\">" RST << std::endl;
        return 1;
    }

    const int max_display = MAXDISPLAY;

    std::cout << WHT "============================PMergeMe=============================" RST << std::endl;

    // LIST PART
    std::list<int> myList = PmergeMe::parseToList(argv[1]);
    std::cout << BLU "List before sort\t: " RST << "\"";
    int count = 0;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end() && count < max_display; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    if (myList.size() > max_display)
    {
        std::cout << "...";
    }
    std::cout << "\"" << std::endl;

    clock_t start = clock();
    PmergeMe::FordJohnson(myList);
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds

    std::cout << (PmergeMe::isSorted(myList) ? GRN "List is sorted!" RST : RED "List is not sorted!" RST) << std::endl;

    std::cout << WHT "Sorted list\t\t: " RST << "\"";
    count = 0;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end() && count < max_display; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    if (myList.size() > max_display)
    {
        std::cout << "...";
    }
    std::cout << "\"" << std::endl;

    std::cout << "->Time to sort list\t: " << std::fixed << std::setprecision(2) << elapsed_time << " μs" << std::endl;
    std::cout << WHT "-----------------------------------------------------------------" RST << std::endl;

    // VECTOR PART
    std::vector<int> myVector = PmergeMe::parseToVec(argv[1]);
    std::cout << CYA "Vector before sort\t: " RST << "\"";
    count = 0;
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end() && count < max_display; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    if (myVector.size() > max_display)
    {
        std::cout << "...";
    }
    std::cout << "\"" << std::endl;

    start = clock();
    PmergeMe::FordJohnson(myVector);
    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds

    std::cout << (PmergeMe::isSorted(myVector) ? GRN "Vector is sorted!" RST : RED "Vector is not sorted!" RST) << std::endl;

    std::cout << WHT "Sorted vector\t\t: " RST << "\"";
    count = 0;
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end() && count < max_display; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    if (myVector.size() > max_display)
    {
        std::cout << "...";
    }
    std::cout << "\"" << std::endl;

    std::cout << "->Time to sort vector\t: " << std::fixed << std::setprecision(2) << elapsed_time << " μs" << std::endl;

    std::cout << WHT "=================================================================" RST << std::endl;

    return 0;
}