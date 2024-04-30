/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:58:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:43:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Cure.hpp"

// Constructor
Cure::Cure() : AMateria("Cure")
{
    std::cout << GRN << "Constructor called for " << this->getType() << RST << std::endl;
}

// Copy Constructor
Cure::Cure(const Cure &src) : AMateria(src)
{
    std::cout << GRN << "Copy constructor called for " << this->getType() << RST << std::endl;
}

// Assignment Operator Overload
Cure& Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
        std::cout << GRN << "Assignment operator called for " << this->getType() << RST << std::endl;
    }
    return *this;
}

// Destructor
Cure::~Cure()
{
    std::cout << RED << "~Destructor called for " << this->getType() << " ~" << RST << std::endl;
}

// Methods
void Cure::use(ICharacter& target)
{
    std::cout << MAG << this->getType() << " : * heals " << target.getName() << " wounds *" RST << std::endl;
    return;
}

Cure* Cure::clone() const
{
    return (new Cure());
}