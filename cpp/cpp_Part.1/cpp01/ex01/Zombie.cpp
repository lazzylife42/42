/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/26 15:31:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << GRN << "Default Constructor called" << RST << std::endl;
    return;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << GRN << "Constructor called for " << this->_name << RST << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << RED << "~Destructor called for : " << this->_name  << " ~"  << RST << std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void randomChump(std::string name)
{
    Zombie* z = newZombie(name);
    z->announce();
    delete z;
    return;
}

Zombie* newZombie(std::string name)
{
    return (new Zombie(name));

}