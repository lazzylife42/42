/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/03 23:56:56 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <sstream>
#include "ScalarConverter.hpp"

// Constructors & Desctructor
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

// Members Functions

// IsSomthing Functions
#include <string>

bool ScalarConverter::isChar(const std::string& input)
{
    if (input.size() == 1)
    {
        return !isdigit(input[0]);
    }
    else if (input.size() == 4 && input.substr(0, 2) == "\\x" && isxdigit(input[2]) && isxdigit(input[3]))
    {
        return true;
    }
    else
    {
        try
        {
            int number = std::stoi(input);
            return (number >= 0 && number <= 255 && !isdigit(number));
        }
        catch (std::invalid_argument& e)
        {
            return false;
        }
    }
}


#include <limits>

#include <cstdlib>
#include <climits>

bool ScalarConverter::isInt(const std::string& input)
{
    if (input.empty())
        return false;

    char* endptr;
    strtol(input.c_str(), &endptr, 10);
    if (*endptr != '\0' || *endptr != 'f') {
        try {
            std::stof(input);
        } catch (...) {
            return false;
        }
    }

    return true;
}



// bool ScalarConverter::isFloat(const std::string& input)
// {
//     if (input.empty() || (!isdigit(input[0]) && input[0] != '-' && input[0] != '+' && input[0] != '.')) {
//         return false;
//     }

//     // Vérifiez chaque caractère de la chaîne
//     for (size_t i = 0; i < input.size(); ++i) {
//         if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != 'F' && input[i] != '-' && input[i] != '+') {
//             return false;
//         }
//     }

//     // Vérifiez qu'il n'y a qu'un seul point décimal
//     int dotCount = 0;
//     for (size_t i = 0; i < input.size(); ++i) {
//         if (input[i] == '.') {
//             ++dotCount;
//         }
//     }

//     return dotCount <= 1;
// }


// bool ScalarConverter::isDouble(const std::string& input)
// {
// }




// toSomething
char ScalarConverter::toChar(const std::string& input)
{
    
    if (input.size() == 1)
    {
        if (!isdigit(input[0]) && !iscntrl(input[0]))
            return input[0];
    }
    else if (input.size() >= 4 && input.substr(0, 2) == "\\x" && isxdigit(input[2]))
    {
        int number;
        try{
            number = std::stoi(input.substr(2), nullptr, 16);
        } catch (...) {return '\0';}
        if (number >= 0 && number <= 255 && !iscntrl(static_cast<char>(number)))
            return static_cast<char>(number);
    }
    else
    {
        try
        {
            int number;
            try {
                number = std::stoi(input);
            } catch (...) {return '\0';}
            if (number >= 0 && number <= 255 && !isdigit(number) && !iscntrl(static_cast<char>(number)))
                return static_cast<char>(number);
        }
        catch (std::invalid_argument& e) {}
    }
    return '\0';
}

int ScalarConverter::toInt(const std::string& input) {
    try {
        // Tentative de conversion en int
        return std::stoi(input);
    } catch (const std::out_of_range& e) {
        try {
            // Tentative de conversion en float puis en int
            return static_cast<int>(std::stof(input));
        } catch (const std::out_of_range& e) {
            return std::numeric_limits<int>::min(); // Impossible
        }
    }
}


// float ScalarConverter::toFloat(const std::string& input)
// {
//     if (!isChar(input))
//     {
//         try
//         {
//             return std::stof(input);
//         }
//         catch (const std::exception& e)
//         {
//             // Gérer les erreurs de conversion ici
//             return std::numeric_limits<float>::quiet_NaN(); // Retourner une valeur spéciale pour indiquer l'échec de la conversion
//         }
//     }
//     return std::numeric_limits<float>::quiet_NaN(); // Retourner une valeur spéciale pour indiquer l'échec de la conversion pour les caractères
// }

// double ScalarConverter::toDouble(const std::string& input)
// {
//     if (!isChar(input))
//     {
//         try
//         {
//             return std::stod(input);
//         }
//         catch (const std::exception& e)
//         {
//             // Gérer les erreurs de conversion ici
//             return std::numeric_limits<double>::quiet_NaN(); // Retourner une valeur spéciale pour indiquer l'échec de la conversion
//         }
//     }
//     return std::numeric_limits<double>::quiet_NaN(); // Retourner une valeur spéciale pour indiquer l'échec de la conversion pour les caractères
// }


// Convert
void ScalarConverter::convert(const std::string& input)
{
    // char Part
    std::cout << BLU "char  :\t\t " RST;
    char c = toChar(input);
    if (c != '\0' && !isdigit(c))
        std::cout << c;
    else
        std::cout << "Impossible";
    std::cout << std::endl;

    // int Part
    std::cout << CYA "int   :\t\t " RST;
    if (isInt(input)) {
        try {
            int value = std::stoi(input);
            std::cout << value;
        } catch (...) {
            std::cout << "Impossible";
        }
    } else {
        std::cout << "Impossible";
    }
    std::cout << std::endl;


    // // float Part
    // std::cout << MAG "float :\t\t " RST;
    // try {
    //     if (isFloat(input))
    //         std::cout << std::fixed << std::setprecision(1) << toFloat(input) << "f";
    //     else
    //         throw std::invalid_argument("Invalid input");
    // }
    // catch (...) {
    //     std::cout << "Impossible";
    // }
    // std::cout << std::endl;

    // // double Part
    // std::cout << YEL "double:\t\t " RST;
    // try {
    //     if (isDouble(input))
    //         std::cout << std::fixed << std::setprecision(1) << toDouble(input);
    //     else
    //         throw std::invalid_argument("Invalid input");
    // }
    // catch (...) {
    //     std::cout << "Impossible";
    // }
    // std::cout << std::endl;
}




