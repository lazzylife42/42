/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:37:08 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:40:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Dog.hpp"

Dog::Dog() : aAnimal()
{
    setType("Dog");
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

Dog::Dog(const Dog &src) : aAnimal(src)
{
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
        aAnimal::operator=(rhs);
    return *this;
}

Dog::~Dog()
{
    std::cout << RED << "~Destructor called for " << getType() << " ~" << RST << std::endl;
}

void Dog::makeSound(void)
{
    std::cout << BLU "🦮 Woaf 🦮" RST << std::endl;
}

