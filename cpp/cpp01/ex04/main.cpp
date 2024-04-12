/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:38:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 17:09:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>

#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << RED << "Bad args.\nTry : <filename> <string1> <string2>" << RST << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    // const char* find = argv[2];
    // const char* replace = argv[3];

    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        // Ici, vous pouvez utiliser votre fonction strremplace pour remplacer find par replace dans la ligne.
        // Exemple : line = strremplace(line.c_str(), find, replace);
        std::cout << line << std::endl;
    }

    return 0;
}