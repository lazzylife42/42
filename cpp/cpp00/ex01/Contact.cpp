/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:52:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/07 16:43:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
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
