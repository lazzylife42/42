/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:53:01 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 19:25:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_health = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << GRN "FragTrap constructor called for " << this->getName() << RST << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << RED "~FragTrap destructor called for " << this->getName() << "~" RST << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << GRN "FragTrap Copy constructor called" RST<< std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_health = rhs._health;
        this->_energy = rhs._energy;
        this->_attack = rhs._attack;
    }
    return *this;
}

// void FragTrap::attack(const std::string& target)
// {
//     if (this->getHealth() <= 0)
//     {
//         std::cout << RED "FragTrap " << this->getName() << " cannot attack, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     else if (this->getEnergy() <= 0)
//     {
//         std::cout << MAG "FragTrap " << this->getName() << " cannot attack, he's out of energy :/" RST << std::endl;
//         return;
//     }
//     std::cout << YEL "FragTrap " << this->getName() << " attacks " 
//         << target << ", causing " << this->_attack << " points of damage!" RST << std::endl;
//     this->setEnergy(this->getEnergy() - 1);
// }

void FragTrap::highFivesGuys(void)
{
    if (this->getHealth() <= 0)
    {
        std::cout << RED "FragTrap " << this->getName() << " cannot High Five, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    std::cout << YEL "FragTrap " << this->getName() << " is asking for a High Five, 😎" RST << std::endl;
}

// void FragTrap::takeDamage(unsigned int amount)
// {
//     if (this->_health <= 0)
//     {
//         std::cout << RED "FragTrap " << this->_name << " cannot take damage, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     std::cout << YEL "FragTrap " << this->_name << " takes " << amount << " points of damage!" RST << std::endl;
//     if (this->_health < amount)
//         this->_health = 0;
//     else
//         this->_health -= amount;
// }

// void FragTrap::beRepaired(unsigned int amount)
// {
//     if (this->_health <= 0)
//     {
//         std::cout << RED "FragTrap " << this->_name << " cannot be repaired, he's DEAD :( \"R.I.P.\"" RST << std::endl;
//         return;
//     }
//     else if (this->_energy <= 0)
//     {
//         std::cout << MAG "FragTrap " << this->_name << " cannot be repaired, he's out of energy :/" RST << std::endl;
//         return;
//     }
//     std::cout << YEL "FragTrap " << this->_name << " is repaired for " << amount << " points of health!" RST<< std::endl;
//     this->_health += amount;
// }