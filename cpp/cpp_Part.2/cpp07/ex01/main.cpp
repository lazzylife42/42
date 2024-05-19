/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:04:19 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/19 19:30:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "color.hpp"
#include <stdio.h>

int main()
{
    std::cout << CLR;

    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << BLU "Integer array:" RST << std::endl;
    iter(intArray, intLen, printNum<int>);

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << CYA "Double array:" RST << std::endl;
    iter(doubleArray, doubleLen, printNum<double>);

    // Test with an array of strings
    std::string strArray[] = {"hello", "world", "!"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << MAG "String array:" RST << std::endl;
    iter(strArray, strLen, printNum<std::string>);

    return 0;
}
