/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:03:01 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/09 22:45:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
    Phonebook ph;
    std::string input;

    while (true)
    {
        std::cout << MAG << "+----------------+" << std::endl;
        std::cout << "|📞 PHONE BOOK 📞|" << std::endl;
        std::cout << "+----------------+" << RST << std::endl;
        std::getline(std::cin, input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input == "PHONEBOOK")
            ph.printBook();
        else if (input == "ADD")
        {
            Contact newContact;
            ph.addContact(newContact);
            ph.addToBook(newContact);
        }
        else if (input == "SEARCH")
            ph.searchContact();
        else if (input == "EXIT")
        {
            std::cout << RED << "EXIT" << RST << std::endl;
            return 0;
        }
        else
            std::cout << RED << "Non." << RST << std::endl;
    }
    return 0;
}
