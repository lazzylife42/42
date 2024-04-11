/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:34:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 11:04:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << GRN << "Constructor Weapon called" << RST << std::endl;
    return;
}

Weapon::~Weapon(void)
{
    std::cout << RED << "~Destructor Weapon called~" << RST << std::endl;
    return;
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
    return;
}