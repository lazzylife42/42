/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:52:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNum(""), darkSecret("")
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
}


Contact::~Contact(void)
{
    std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}

// Getter
const std::string& Contact::getStringRef(const std::string& target) const 
{
    if (target == "firstName")
        return firstName;
    else if (target == "lastName")
        return lastName;
    else if (target == "nickName")
        return nickName;
    else if (target == "phoneNum")
        return phoneNum;
    else if (target == "darkSecret")
        return darkSecret;
    else
        throw std::invalid_argument("Invalid target");
}

// Setter
void Contact::setStringRef(const std::string& target, const std::string& newString)
{
    if (target == "firstName")
        firstName = newString;
    else if (target == "lastName")
        lastName = newString;
    else if (target == "nickName")
        nickName = newString;
    else if (target == "phoneNum")
        phoneNum = newString;
    else if (target == "darkSecret")
        darkSecret = newString;
    else
        throw std::invalid_argument("Invalid target");
}
