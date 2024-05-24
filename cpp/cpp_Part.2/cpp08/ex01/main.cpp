/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:49:18 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/24 17:04:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp = Span(10);
        
        // std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> moreNumbers;
        moreNumbers.push_back(1);
        moreNumbers.push_back(2);
        moreNumbers.push_back(3);
        moreNumbers.push_back(4);
        moreNumbers.push_back(5);
        sp.addNumber(moreNumbers.begin(), moreNumbers.end());
        // sp.addNumber(moreNumbers.begin(), moreNumbers.end());

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}