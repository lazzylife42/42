/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:33:55 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 19:19:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_health = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << GRN "ScavTrap constructor called for " << this->getName() << RST << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED "~ScavTrap destructor called for " << this->getName() << "~" RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << GRN "ScavTrap Copy constructor called" RST<< std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_health = rhs._health;
        this->_energy = rhs._energy;
        this->_attack = rhs._attack;
    }
    return *this;
}

// void ScavTrap::attack(const std::string& target)
// {
//     if (this->getHealth() <= 0)
//     {
//         std::cout << RED "ScavTrap " << this->getName() << " cannot attack, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     else if (this->getEnergy() <= 0)
//     {
//         std::cout << MAG "ScavTrap " << this->getName() << " cannot attack, he's out of energy :/" RST << std::endl;
//         return;
//     }
//     std::cout << CYA "ScavTrap " << this->getName() << " attacks " 
//         << target << ", causing " << this->_attack << " points of damage!" RST << std::endl;
//     this->setEnergy(this->getEnergy() - 1);
// }

void ScavTrap::guardGate(void)
{
    if (this->getHealth() <= 0)
    {
        std::cout << RED "ScavTrap " << this->getName() << " cannot Gate Keep, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    std::cout << CYA "ScavTrap " << this->getName() << " is in Gate Keeper Mode, \"Contrôl le Rinté\"" RST << std::endl;
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
//     if (this->_health <= 0)
//     {
//         std::cout << RED "ScavTrap " << this->_name << " cannot take damage, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     std::cout << YEL "ScavTrap " << this->_name << " takes " << amount << " points of damage!" RST << std::endl;
//     if (this->_health < amount)
//         this->_health = 0;
//     else
//         this->_health -= amount;
// }

// void ScavTrap::beRepaired(unsigned int amount)
// {
//     if (this->_health <= 0)
//     {
//         std::cout << RED "ScavTrap " << this->_name << " cannot be repaired, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     else if (this->_energy <= 0)
//     {
//         std::cout << MAG "ScavTrap " << this->_name << " cannot be repaired, he's out of energy :/" RST << std::endl;
//         return;
//     }
//     std::cout << YEL "ScavTrap " << this->_name << " is repaired for " << amount << " points of health!" RST<< std::endl;
//     this->_health += amount;
// }