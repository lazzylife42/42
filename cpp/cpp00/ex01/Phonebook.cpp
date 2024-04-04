/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:55:28 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 21:14:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
        std::cout << MAG << i + 1 << ") "<< RST << 
            Phonebook::contact->firstName[i] << std::endl;
    return;    
}

void Phonebook::addContact(Contact &contact)
{
    std::cout << MAG << "+-----------------+" << std::endl;
    std::cout << "|📞 ADD CONTACT 📞|" << std::endl;
    std::cout << "+-----------------+" << RST << std::endl;
    std::cout << "First Name :" << std::endl;
    std::cin.getline(contact.firstName, 64);
    std::cout << "Last Name :" << std::endl;
    std::cin.getline(contact.lastName, 64);
    std::cout << "Nick Name :" << std::endl;
    std::cin.getline(contact.nickName, 64);
    std::cout << "Phone Number :" << std::endl;
    std::cin.getline(contact.phoneNum, 11);
    std::cout << "Dark Secret 🤫 :" << std::endl;
    std::cin.getline(contact.darkSecret, 256);
}

void Phonebook::addToBook(Contact& newContact)
{
    addContact(newContact);
    // for (int i = 0; i < 8; i++)
    // {
    //     if (contact[i].firstName[0] == '\0')
    //     {
    //         std::strcpy(contact[i].firstName, newContact.firstName);
    //         std::strcpy(contact[i].lastName, newContact.lastName);
    //         std::strcpy(contact[i].nickName, newContact.nickName);
    //         std::strcpy(contact[i].phoneNum, newContact.phoneNum);
    //         std::strcpy(contact[i].darkSecret, newContact.darkSecret);
    //         return;
    //     }
    // }
    std::cout << "Le carnet d'adresses est plein. Impossible d'ajouter un nouveau contact." << std::endl;
}