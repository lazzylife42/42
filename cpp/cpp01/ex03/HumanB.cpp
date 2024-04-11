/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:07:49 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 12:23:59 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL) 
{
    std::cout << GRN << "Constructor Human B called for : " << this->_name << RST << std::endl;
    return;
}

HumanB::~HumanB(void)
{
    std::cout << RED << "~Destructor Human B called~ for : " << this->_name << RST << std::endl;
    return;
}

void HumanB::attack(void) const
{
    if (_weapon == NULL)
    {
        std::cout << RED << this->_name << " must have a weapon " << _weapon->getType() << std::endl;
        return;
    }
    std::cout << CYA << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    _weapon = &newWeapon;
    return;
}
