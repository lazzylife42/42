/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/16 17:19:08 by smonte-e         ###   ########.fr       */
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
}

bool ScalarConverter::isInt(const std::string& input)
{
}

bool ScalarConverter::isFloat(const std::string& input)
{
}

bool ScalarConverter::isDouble(const std::string& input)
{
}


/// toSomething
char ScalarConverter::toChar(const std::string& input)
{
}


int ScalarConverter::toInt(const std::string& input)
{
}

static float	toFloat(const std::string& input)
{
}

static double	toDouble(const std::string& input)
{
}

// Convert
void ScalarConverter::convert(const std::string& input)
{
}




