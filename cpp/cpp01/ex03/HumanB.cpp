/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:07:49 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 11:04:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) , weapon("None") 
{
    std::cout << GRN << "Constructor Human B called" << RST << std::endl;
    return;
}

HumanB::~HumanB(void)
{
    std::cout << RED << "~Destructor Human B called~" << RST << std::endl;
    return;
}

void HumanB::attack(void) const
{
    std::cout << CYA << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(const Weapon& newWeapon)
{
    weapon = newWeapon;
    return;
}
