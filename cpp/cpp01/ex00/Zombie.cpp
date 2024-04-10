/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/10 18:15:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << RED << "~Destructor called for : " << RST << this->name << RED << " ~"  << RST << std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

void Zombie::nameZombie(std::string name)
{
    this->name = name;
    return;
}
