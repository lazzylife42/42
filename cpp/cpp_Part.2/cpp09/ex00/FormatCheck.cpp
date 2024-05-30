/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormatCheck.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:08:04 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/30 16:18:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "FormatCheck.hpp"

FormatCheck::FormatCheck() {}
FormatCheck::FormatCheck(FormatCheck const& src) { (void)src; }
FormatCheck& FormatCheck::operator=(const FormatCheck& rhs) { (void)rhs; return (*this); }
FormatCheck::~FormatCheck() {}

bool FormatCheck::isValidDate(const std::string& input)
{
    std::istringstream in(input);
    int year, month, day;
    char delimiter1, delimiter2;

    if (in >> year >> delimiter1 >> month >> delimiter2 >> day)
    {
        if (delimiter1 == '-' && delimiter2 == '-')
        {
            if (year >= 0 && month >= 1 && month <= 12)
            {
                int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                    daysInMonth[1] = 29;
                if (day >= 1 && day <= daysInMonth[month - 1])
                    return true;
            }
        }
    }
    return false;
}

bool FormatCheck::isValidPrice(const std::string &input)
{
    std::istringstream in(input);
    float price;
    
    if (!(in >> price))
        return false;

    char extra;
    if (in >> extra)
        return false;
        
    return (price >= 0.0f && price <= 1000.0f);
}

bool FormatCheck::isValidFile(const std::string &filePath)
{
    size_t dotPosition = filePath.find_last_of(".");
    if (dotPosition == std::string::npos)
        return false;

    std::string extension = filePath.substr(dotPosition + 1);
    return (extension == "csv" || extension == "txt");
}

const std::string& FormatCheck::findNearestDate(const std::map<std::string, float> &db, const std::string &input)
{
    if (!isValidDate(input))
        throw std::invalid_argument("Invalid date format");

    std::map<std::string, float>::const_iterator it = db.lower_bound(input);

    if (it == db.begin())
        throw std::runtime_error("No earlier date found");

    if (it == db.end() || it->first != input)
        --it;

    if (it->first > input)
        throw std::runtime_error("No earlier date found");
    return it->first;
}
