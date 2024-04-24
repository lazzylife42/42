/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:22:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:38:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

aAnimal::aAnimal() : _type("No type"), _brain(new Brain())
{
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

aAnimal::aAnimal(const aAnimal &src)
{
    setType("No Type");
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
    _type = src.getType();
    _brain = new Brain(*(src._brain));
}

aAnimal& aAnimal::operator=(const aAnimal &rhs)
{
    if (this != &rhs)
    {
        _type = rhs.getType();
        *_brain = *(rhs._brain);
    }
    return *this;
}

aAnimal::~aAnimal()
{
    delete _brain;
    std::cout << RED << "~Destructor called for " << getType() << " ~"<< RST << std::endl;
}

// Getter
std::string aAnimal::getType(void) const
{
    return _type;
}

Brain* aAnimal::getBrain(void) const
{
    return _brain;
}

// Setter
void aAnimal::setType(std::string type)
{
    _type = type;
}

// Méthode makeSound
void aAnimal::makeSound(void)
{
    std::cout << YEL << "* Unrecognized aanimal sound *" << RST << std::endl;
}
