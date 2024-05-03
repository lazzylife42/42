/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/03 16:48:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cmath>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include "ScalarConverter.hpp"

// Constructors & Desctructor
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

// Members Functions

// IsSomthing Functions
bool	ScalarConverter::isChar(const std::string& input)
{
    return (input.size() == 1);
}

bool ScalarConverter::isInt(const std::string& input)
{
    std::istringstream iss(input);
    int temp;
    return (iss >> temp) && iss.eof();
}

bool ScalarConverter::isFloat(const std::string& input)
{
    std::istringstream iss(input);
    float temp;
    return (iss >> temp) && iss.eof();
}

bool ScalarConverter::isDouble(const std::string& input)
{
    std::istringstream iss(input);
    double temp;
    return (iss >> temp) && iss.eof();
}

// toSomething
char	ScalarConverter::toChar(const std::string& input)
{
    return (static_cast<char>(input.at(0)));
}

int ScalarConverter::toInt(const std::string& input)
{
    if (isChar(input))
    {
        char c = toChar(input);
        return static_cast<unsigned char>(c);
    }
    return (static_cast<int>(stoi(input)));
}

float ScalarConverter::toFloat(const std::string& input)
{
    return (static_cast<float>(stof(input)));
}

double	ScalarConverter::toDouble(const std::string& input)
{
    return (static_cast<double>(stod(input)));
}

// Convert
void ScalarConverter::convert(const std::string& input)
{
    // char Part
    std::cout << BLU "char  :\t\t " <<RST;
    if (!isprint(stoi(input)))
            std::cout << "Non displayable";
    else if (isChar(input))
    {
        char c = toChar(input);
        if (std::isprint(c))
            std::cout.put(c);
    }
    else
        std::cout << "Impossible";
    std::cout << std::endl;
    
    // int Part
    std::cout << CYA "int   :\t\t " RST;
    try {
        if (input.length() == 1 && isdigit(input.at(0)))
            std::cout << toChar(input);
        else if(isFloat(input) || isDouble(input))
            std::cout << toInt(input);
        else
            std::cout << "Impossible";
    }
    catch (...) {
        std::cout << "Impossible";
    }
    std::cout << std::endl;
    
    // float Part
    std::cout << MAG "float :\t\t " RST;
    try {
        if(isFloat(input)) {
            float floatValue = toFloat(input);
            if (std::isnan(floatValue))
                std::cout << "nanf";
            else if (std::isinf(floatValue)) {
                if (floatValue > 0)
                    std::cout << "+inff";
                else
                    std::cout << "-inff";
            }
            else
                std::cout << std::fixed << std::setprecision(1) << floatValue << "f";
        } else
            std::cout << "Impossible";
    }
    catch (...) {
        std::cout << "Impossible";
    }
    std::cout << std::endl;

    // double Part
    std::cout << YEL "double:\t\t " RST;
    try {
        if(isDouble(input)) {
            double doubleValue = toDouble(input);
            if (std::isnan(doubleValue))
                std::cout << "nan";
            else if (std::isinf(doubleValue)) {
                if (doubleValue > 0)
                    std::cout << "+inf";
                else
                    std::cout << "-inf";
            }
            else
                std::cout << std::fixed << std::setprecision(1) << doubleValue;
        } else
            std::cout << "Impossible";
    }
    catch (...) {
        std::cout << "Impossible";
    }
    std::cout << std::endl;
}


