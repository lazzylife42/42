/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:46:49 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 11:46:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << GRN << "Constructor Human A called for : " << this->_name << RST << std::endl;
    return;
}

HumanA::~HumanA(void)
{
    std::cout << RED << "~Destructor Human A called~ for : "<< this->_name << RST << std::endl;
    return;
}

void HumanA::attack(void) const
{
    std::cout << MAG << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
    return;
}