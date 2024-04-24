/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:22:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:08:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("No type"), _brain(new Brain())
{
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

Animal::Animal(const Animal &src)
{
    setType("No Type");
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
    _type = src.getType();
    _brain = new Brain(*(src._brain));
}

Animal& Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
    {
        _type = rhs.getType();
        *_brain = *(rhs._brain);
    }
    return *this;
}

Animal::~Animal()
{
    delete _brain;
    std::cout << RED << "~Destructor called for " << getType() << " ~"<< RST << std::endl;
}

// Getter
std::string Animal::getType(void) const
{
    return _type;
}

Brain* Animal::getBrain(void) const
{
    return _brain;
}

// Setter
void Animal::setType(std::string type)
{
    _type = type;
}

// Méthode makeSound
void Animal::makeSound(void)
{
    std::cout << YEL << "* Unrecognized animal sound *" << RST << std::endl;
}
