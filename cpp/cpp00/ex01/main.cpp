/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:03:01 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/06 19:22:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    Phonebook ph;
    char input[64];

    while (true)
    {
        std::cout << MAG << "+----------------+" << std::endl;
        std::cout << "|📞 PHONE BOOK 📞|" << std::endl;
        std::cout << "+----------------+" << RST << std::endl;
        std::cin.getline(input, 64);

        if (std::strcmp(input, "PHONEBOOK") == 0)
            ph.printBook();
        else if (std::strcmp(input, "ADD") == 0)
            ph.addToBook(ph.contact[0]);  
        else if (std::strcmp(input, "EXIT") == 0)
            return 0;
        else
            std::cout << RED << "Non." << RST << std::endl;
    }
    return 0;
}