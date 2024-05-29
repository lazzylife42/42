/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:48:32 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/30 01:20:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "color.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << RED "Bad Args. 🥲\n" BLU "Try ./btc <db.csv> <date(s)_to_check.something>" RST << std::endl;
        return 1;
    }

    std::map<std::string, float> db;
    std::ifstream file(argv[1]);
    
    if (!file.is_open())
    {
        std::cerr << RED "Error opening file: " << argv[1] << RST << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price_str;
        
        if (std::getline(ss, date, ',') && std::getline(ss, price_str) && !line.empty())
        {
            std::istringstream price_stream(price_str);
            float price;
            price_stream >> price;
            db[date] = price;
        }
    }

    file.close();

    for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); ++it)
    {
        std::cout << BLU "Date: " << it->first << CYA " | Price: " << it->second << RST << std::endl;
    }

    return 0;
}
