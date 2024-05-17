/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 14:47:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <iomanip>
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

bool ScalarConverter::formatCheck(const std::string& input)
{
    int dot = 0;
    int f = 0;
    int digit = 0;
    size_t i = 0;

    if (input[0] == '-' || input[0] == '+')
        i++;
        
    for (; i < input.length(); i++)
    {
        if (isdigit(input[i]))
            digit++;
        else if (input[i] == '.')
        {
            dot++;
            if (dot > 1 || f > 0)
                return false;
        }
        else if (input[i] == 'f')
        {
            f++;
            if (i != input.length() - 1 || f > 1)
                return false;
        }
        else
            return false;
    }
    if (digit == 0)
        return false;
    return true;
}


bool ScalarConverter::isInt(const std::string& input)
{
    long value;
    
    if (input.empty())
        return false;
    try {
        value = stol(input);
    } catch (...) {return false;}
    if (value <= INT_MAX && value >= INT_MIN)
        return true;
    return false;
}

bool ScalarConverter::isFloat(const std::string& input)
{
    float value;
    
    if (input.empty())
        return false;
    if (input == "nan" || input == "nanf" || input == "inf" || input == "inff"
        || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
        return true;
    try {
        value = stof(input);
    } catch (...) {return false;}
    return true;
}

bool ScalarConverter::isDouble(const std::string& input)
{
    double value;
    
    if (input.empty())
        return false;
    if (input == "nan" || input == "nanf" || input == "inf" || input == "inff"
        || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
        return true;
    try {
        value = stod(input);
    } catch (...) {return false;}
    return true;
}


/// toSomething
char ScalarConverter::toChar(const std::string& input)
{
    int value;
    char* endptr;
    
    value = strtol(input.c_str(), &endptr, 10);
    if (input.length() == 1 && !isdigit(input[0]))
        return static_cast<char>(input[0]);
    return value;
}


int ScalarConverter::toInt(const std::string& input)
{
    return static_cast<int>(stoi(input));    
}

float ScalarConverter::toFloat(const std::string& input)
{
    return static_cast<float>(stof(input));
}

double ScalarConverter::toDouble(const std::string& input)
{
    return static_cast<double>(stod(input));
}

// Convert
void ScalarConverter::convert(const std::string& input)
{
    // Char Part
    std::cout << BLU << "char\t\t" << RST;
    if (isChar(input))
    {
        if (input.length() > 1 && formatCheck(input))
        {
            if (isprint(toChar(input)))
                std::cout << toChar(input);
            else 
                std::cout << "Non displayable";         
        }
        else if (input.length() == 1)
        {
            if (isprint(toChar(input)))
                std::cout << toChar(input);
            else
                std::cout << "Non displayable";
        }
        else
            std::cout << "Impossible";
    }
    else
        std::cout << "Impossible";
    std::cout << RST << std::endl;

    // Int Part
    std::cout << CYA << "int\t\t" << RST;
    if (isInt(input) && formatCheck(input))
        std::cout << toInt(input);
    else
        std::cout << "Impossible";
    std::cout << RST << std::endl;
    
    // Float Part
    std::cout << MAG << "float\t\t" << RST;
    if (isFloat(input) && formatCheck(input))
        std::cout << std::fixed << std::setprecision(1) << toFloat(input) << "f";
    else if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf")
        std::cout << input << "f";
    else if (input == "nanf" || input == "inff"|| input == "+inff" || input == "-inff")
        std::cout << input;
    else
        std::cout << "Impossible";
    std::cout << RST << std::endl;

    // Double Part
    std::cout << YEL << "double\t\t" << RST;
    if (isDouble(input) && formatCheck(input))
        std::cout << std::fixed << std::setprecision(1) << toDouble(input);
    else if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf")
        std::cout << input;
    else if (input == "nanf" || input == "inff"|| input == "+inff" || input == "-inff")
    {
        std::string temp = input;
        temp.pop_back();
        std::cout << temp;
    }
    else
        std::cout << "Impossible";
    std::cout << RST << std::endl;
}




