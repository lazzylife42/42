/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:54 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/18 19:21:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack(0)
{
    std::cout << GRN "Constructor called for " << this->_name << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED "~Destructor called for " << this->_name << "~" RST<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_health = rhs._health;
        this->_energy = rhs._energy;
        this->_attack = rhs._attack;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot attack, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    else if (this->_energy <= 0)
    {
        std::cout << MAG "ClapTrap " << this->_name << " cannot attack, he's out of energy :/" RST << std::endl;
        return;
    }
    std::cout << BLU "ClapTrap " << this->_name << " attacks " 
        << target << ", causing " << this->_attack << " points of damage!" RST << std::endl;
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot take damage, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    std::cout << YEL "ClapTrap " << this->_name << " takes " << amount << " points of damage!" RST << std::endl;
    if (this->_health < amount)
        this->_health = 0;
    else
        this->_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_health <= 0)
    {
        std::cout << RED "ClapTrap " << this->_name << " cannot be repaired, he's DEAD :( \"R.I.P.\"" RST << std::endl;
        return;
    }
    else if (this->_energy <= 0)
    {
        std::cout << MAG "ClapTrap " << this->_name << " cannot be repaired, he's out of energy :/" RST << std::endl;
        return;
    }
    std::cout << YEL "ClapTrap " << this->_name << " is repaired for " << amount << " points of health!" RST<< std::endl;
    this->_health += amount;
}

