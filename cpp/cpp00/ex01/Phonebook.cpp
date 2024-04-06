/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:55:28 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/06 19:21:48 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook(void)
{
    std::cout << GRN << "📞Constructor called📞" << RST << std::endl;
    return;
}

Phonebook::~Phonebook(void)
{
    std::cout << RED << "📞~Destructor called~📞" << RST << std::endl;
    return;
}

void Phonebook::printBook(void) const
{
    for (int i = 0; i < 8; i++)
        std::cout << MAG << i + 1 << ") " << RST <<
        this->contact[i].firstName << std::endl;
    return;
}

void Phonebook::addContact(Contact& contact)
{
    std::cout << MAG << "+-----------------+" << std::endl;
    std::cout << "|📞 ADD CONTACT 📞|" << std::endl;
    std::cout << "+-----------------+" << RST << std::endl;
    do {
        std::cout << "First Name :" << std::endl;
        std::cin.getline(contact.firstName, 64);
    } while (strlen(contact.firstName) == 0);
    do {
        std::cout << "Last Name :" << std::endl;
        std::cin.getline(contact.lastName, 64);
    } while (strlen(contact.lastName) == 0);
    do {
        std::cout << "Nick Name :" << std::endl;
        std::cin.getline(contact.nickName, 64);
    } while (strlen(contact.nickName) == 0);
    do {
        std::cout << "Phone Number :" << std::endl;
        std::cin.getline(contact.phoneNum, 11);
    } while (strlen(contact.phoneNum) == 0);
    do {
        std::cout << "Dark Secret 🤫 :" << std::endl;
        std::cin.getline(contact.darkSecret, 256);
    } while (strlen(contact.darkSecret) == 0);
}

void Phonebook::addToBook(Contact& newContact)
{
    for (int i = 7; i >= 0; i--)
    {
        std::strcpy(contact[i + 1].firstName, contact[i].firstName);
        std::strcpy(contact[i + 1].lastName, contact[i].lastName);
        std::strcpy(contact[i + 1].nickName, contact[i].nickName);
        std::strcpy(contact[i + 1].phoneNum, contact[i].phoneNum);
        std::strcpy(contact[i + 1].darkSecret, contact[i].darkSecret);
    }
    std::strcpy(contact[0].firstName, newContact.firstName);
    std::strcpy(contact[0].lastName, newContact.lastName);
    std::strcpy(contact[0].nickName, newContact.nickName);
    std::strcpy(contact[0].phoneNum, newContact.phoneNum);
    std::strcpy(contact[0].darkSecret, newContact.darkSecret);
    addContact(newContact);
}
