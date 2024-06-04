/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:48:32 by smonte-e          #+#    #+#             */
/*   Updated: 2024/06/04 15:02:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "color.hpp"
#include "FormatCheck.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << RED "Bad Args. 😢\n" BLU "Try ./btc <db.csv> <date(s)_to_check.something>" RST << std::endl;
        return 1;
    }

    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    if (!file1.is_open() || !FormatCheck::isValidFile(argv[1]))
    {
        std::cerr << RED "Error opening file: " << argv[1] << RST << std::endl;
        return 1;
    }
    else if (!file2.is_open() || !FormatCheck::isValidFile(argv[2]))
    {
        std::cerr << RED "Error opening file: " << argv[2] << RST << std::endl;
        return 1;
    }

    std::map<std::string, float> db;

    std::string line;
    while (std::getline(file1, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price_str;

        if (std::getline(ss, date, ',') && std::getline(ss, price_str))
        {
            std::istringstream price_stream(price_str);
            float price;
            price_stream >> price;
            db[date] = price;
        }
    }
    file1.close();

    std::string file2line;
    while (std::getline(file2, file2line))
    {
        std::stringstream file2ss(file2line);
        std::string file2date;
        std::string file2price_str;

        if (std::getline(file2ss, file2date, '|') && (std::getline(file2ss, file2price_str) || file2price_str.empty()))
        {
            std::istringstream file2price_stream(file2price_str);
            float file2price;
            file2price_stream >> file2price;

            if (FormatCheck::isValidDate(file2date) && FormatCheck::isValidPrice(file2price_str))
            {
                try
                {
                    const std::string& nearestDate = FormatCheck::findNearestDate(db, file2date);
                    std::cout << CYA << file2date << WHT " \t      => " CYA << db[nearestDate] * file2price << RST << std::endl;
                }
                catch (const std::exception &e) { std::cerr << RED "Error: " << e.what() << RST << std::endl; }
            }
            else if (!FormatCheck::isValidDate(file2date) && file2date != "date ")
            {
                std::cerr << RED "Error: bad date input" WHT " => " RED << file2date << RST << std::endl;
            }
            else if (!FormatCheck::isValidPrice(file2price_str))
            {
                if (file2price < 0.0f)
                    std::cerr << RED "Error: not a positive number." << RST << std::endl;
                else if (file2price > 1000.0f)
                    std::cerr << RED "Error: too large a number." << RST << std::endl;
                else
                    std::cerr << RED "Error: parsing error." << RST << std::endl;
            }
        }
    }
    file2.close();

    return 0;
}
