/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:34:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 11:51:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << GRN << "Constructor Weapon called : " << this->_type << RST << std::endl;
    return;
}

Weapon::~Weapon(void)
{
    std::cout << RED << "~Destructor Weapon called~ : " << this->_type << RST << std::endl;
    return;
}

std::string Weapon::getType() const
{
    return _type;
}

void Weapon::setType(const std::string newType)
{
    _type = newType;
    return;
}