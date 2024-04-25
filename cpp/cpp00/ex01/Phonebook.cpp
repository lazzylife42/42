/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:55:28 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 17:55:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Phonebook.hpp"
#include "Contact.hpp"


Phonebook::Phonebook()
{
    std::cout << GRN << "📞Constructor called📞" << RST << std::endl;
}

Phonebook::~Phonebook()
{
    std::cout << RED << "📞~Destructor called~📞" << RST << std::endl;
}

void Phonebook::printBook() const
{
    for (int i = 0; i < 8; i++)
        std::cout << MAG << i + 1 << ") " << RST << contact[i].getStringRef("firstName") << std::endl;
}

void Phonebook::addContact(Contact& contact)
{
    std::cout << MAG << "+-----------------+" << std::endl;
    std::cout << "|📞 ADD CONTACT 📞|" << std::endl;
    std::cout << "+-----------------+" << RST << std::endl;

    std::string newString;

    do {
        std::cout << "First Name :" << std::endl;
        std::getline(std::cin, newString);
    } while (newString.empty());
    contact.setStringRef("firstName", newString);
    
    do {
        std::cout << "Last Name :" << std::endl;
        std::getline(std::cin, newString);
    } while (newString.empty());
    contact.setStringRef("lastName", newString);
    
    do {
        std::cout << "Nick Name :" << std::endl;
        std::getline(std::cin, newString);
    } while (newString.empty());
    contact.setStringRef("nickName", newString);
    
    do {
        std::cout << "Phone Number :" << std::endl;
        std::getline(std::cin, newString);
    } while (newString.empty());
    contact.setStringRef("phoneNum", newString);
    
    do {
        std::cout << "Dark Secret 🤫 :" << std::endl;
        std::getline(std::cin, newString);
    } while (newString.empty());
    contact.setStringRef("darkSecret", newString);
}

void Phonebook::searchContact() const
{
    std::cout << MAG << "Index | First Name | Last Name  | Nickname  " << RST << std::endl;
    std::cout << MAG << "+-----+------------+------------+-----------+" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << std::right << MAG << i + 1 << "  | " << RST;
        std::cout << std::setw(10) << std::right << truncateString(contact[i].getStringRef("firstName"), 10) << MAG << " | " << RST;
        std::cout << std::setw(10) << std::right << truncateString(contact[i].getStringRef("lastName"), 10) << MAG << " | " << RST;
        std::cout << std::setw(10) << std::right << truncateString(contact[i].getStringRef("nickName"), 10) << std::endl;
    }

    std::cout << std::endl << MAG << "🔎 Entrez l'index du contact à afficher : " << RST << std::endl;
    int index;
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << RED << "\nFin de la saisie. Opération annulée." << RST << std::endl;
            exit(0);
        }
        if (std::all_of(input.begin(), input.end(), ::isdigit))
        {
            index = std::stoi(input);
            if (index >= 1 && index <= 8)
                break;
            else
                std::cout << RED << "Index incorrect. Entrez un nombre entre 1 et 8 : " << RST << std::endl;
        }
        else
            std::cout << RED << "Entrée non valide. Entrez un nombre valide : " << RST << std::endl;
    }
    std::cout << std::endl;
    if (index >= 1 && index <= 8)
    {
        std::cout << "First Name:   " << contact[index - 1].getStringRef("firstName") << std::endl;
        std::cout << "Last Name:    " << contact[index - 1].getStringRef("lastName") << std::endl;
        std::cout << "Nick Name:    " << contact[index - 1].getStringRef("nickName") << std::endl;
        std::cout << "Phone Number: " << contact[index - 1].getStringRef("phoneNum") << std::endl;
        std::cout << "Dark Secret:  " << contact[index - 1].getStringRef("darkSecret") << std::endl;
    }
    else
        std::cout << RED << "Index incorrect." << RST << std::endl;
}

void Phonebook::addToBook(Contact& newContact)
{
    for (int i = 7; i > 0; i--)
        contact[i] = contact[i - 1];
    contact[0] = newContact;
}

std::string Phonebook::truncateString(const std::string& str, size_t length) const {
    if (str.length() <= length)
        return str;
    else
        return str.substr(0, length - 1) + ".";
}
