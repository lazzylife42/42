/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:33:51 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/31 12:27:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PmergeMe.hpp"
#include "color.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Usage: ./PmergeMe <\"numbers\">" RST << std::endl;
        return 1;
    }

    std::cout << WHT "========================PMergeMe========================" RST << std::endl;
    
    // LIST PART
    std::list<int>& myList = PmergeMe::parseToList(argv[1]);
    std::cout << BLU "List before sort     : " RST << "\"";
    int count = 0;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end() && count < 10; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    std::cout << "\"" << std::endl;

    clock_t start = clock();
    PmergeMe::sortContainer(myList);
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds

    std::cout << WHT "Sorted list          : " RST << "\"";
    count = 0;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end() && count < 10; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    std::cout << " \"" << std::endl;

    std::cout << "->Time to sort list  : " << std::fixed << std::setprecision(2) << elapsed_time << " μs" << std::endl;
    std::cout << WHT "--------------------------------------------------------" RST << std::endl;
    
    // VECTOR PART
    std::vector<int>& myVector = PmergeMe::parseToVec(argv[1]);
    std::cout << CYA "Vector before sort   : " RST << "\"";
    count = 0;
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end() && count < 10; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    std::cout << "\"" << std::endl;

    start = clock();
    PmergeMe::sortContainer(myVector);
    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6; // convert to microseconds

    std::cout << WHT "Sorted vector        : " RST << "\"";
    count = 0;
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end() && count < 10; ++it, ++count)
    {
        std::cout << *it << " ";
    }
    std::cout << " \"" << std::endl;

    std::cout << "->Time to sort vector: " << std::fixed << std::setprecision(2) << elapsed_time << " μs" << std::endl;

    std::cout << WHT "========================================================" RST << std::endl;
    
    return 0;
}
