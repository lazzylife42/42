/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:38:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 10:51:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << RED << "Bad args.\nTry : <filename> <string1> <string2>" << RST << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    const char* find = argv[2];
    const char* replace = argv[3];

    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        std::cerr << RED << "Failed to open file: " << filename << RST << std::endl;
        return 1;
    }

    std::string outputFilename = std::string(filename) + ".replace";
    std::ofstream ofs(outputFilename);
    if (!ofs.is_open())
    {
        std::cerr << RED << "Failed to create output file: " << outputFilename << RST << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        std::string result = replaceString(line, find, replace);
        ofs << result << std::endl;
    }

    std::cout << GRN << "🖋 Output written to " << outputFilename << " 🖋" << RST << std::endl;
    return 0;
}
