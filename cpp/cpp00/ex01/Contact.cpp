/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:52:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 21:11:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
    this->firstName[0] = '\0';
    this->lastName[0] = '\0';
    this->nickName[0] = '\0';
    this->phoneNum[0] = '\0';
    this->darkSecret[0] = '\0';
    return;
}

Contact::~Contact(void)
{
    std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}
