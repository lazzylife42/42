/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 01:07:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <climits>
#include <cstdlib>
#include <sstream>
#include "ScalarConverter.hpp"

// Constructors & Desctructor
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

// Members Functions

/// IsSomthing Functions
bool ScalarConverter::isChar(const std::string& input)
{
    int value;
    char* endptr;
    
    if (input.empty())
        return false;
    try {
        value = strtol(input.c_str(), &endptr, 10);
    } catch (...) {return false;}
    if (input.length() == 1 && input[0] >= 0 && input[0] <= 127)
        return true;
    if (value >= 0 && value <= 127 && (*endptr == '\0' || *endptr == '.' || *endptr == 'f'))
        return true;
    return false;
}

// bool ScalarConverter::isInt(const std::string& input)
// {
// }

// bool ScalarConverter::isFloat(const std::string& input)
// {
// }

// bool ScalarConverter::isDouble(const std::string& input)
// {
// }


/// toSomething
// char ScalarConverter::toChar(const std::string& input)
// {
// }


// int ScalarConverter::toInt(const std::string& input)
// {
// }

// static float	toFloat(const std::string& input)
// {
// }

// static double	toDouble(const std::string& input)
// {
// }

// Convert
void ScalarConverter::convert(const std::string& input)
{
    std::cout << WHT "Value " << input;
    if (isChar(input))
        std::cout << GRN " True";
    else
        std::cout << RED " False";
    std::cout << RST << std::endl;
}




