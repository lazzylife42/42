/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:46:49 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:43:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Ice.hpp"

// Constructor
Ice::Ice() : AMateria("ice")
{
    std::cout << GRN << "Constructor called for " << this->getType() << RST << std::endl;
}

// Copy Constructor
Ice::Ice(const Ice &src) : AMateria(src)
{
    std::cout << GRN << "Copy constructor called for " << this->getType() << RST << std::endl;
}

// Assignment Operator Overload
Ice& Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
        std::cout << GRN << "Assignment operator called for " << this->getType() << RST << std::endl;
    }
    return *this;
}

// Destructor
Ice::~Ice()
{
    std::cout << RED << "~Destructor called for " << this->getType() << " ~" << RST << std::endl;
}

// Methods
void Ice::use(ICharacter& target)
{
    std::cout << BLU << this->getType() << " : * shoots an ice bolt at " << target.getName() << " *" RST << std::endl;
    return;
}

Ice* Ice::clone() const
{
    return (new Ice());
}