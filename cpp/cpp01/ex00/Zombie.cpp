/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:29:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/26 15:28:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

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

