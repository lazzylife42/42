/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:31:11 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/10 19:48:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include <iostream>

int main(void)
{
    std::string variable = "HI THIS IS BRAIN";
    std::string* stringPTR = &variable;
    std::string& stringREF = variable;

    std::cout << GRN << "The memory address of the string variable : " << &variable << RST << std::endl;
    std::cout << CYA << "The memory address held by stringPTR      : " << stringPTR << RST << std::endl;
    std::cout << MAG << "The memory address held by stringREF      : " << &stringREF << RST << std::endl;

    std::cout << GRN << "The value of the string variable          : " << variable << RST << std::endl;
    std::cout << CYA << "The value pointed to by stringPTR         : " << *stringPTR << RST << std::endl;
    std::cout << MAG << "The value pointed to by stringREF         : " << stringREF << RST << std::endl;
    return 0;
}

#endif