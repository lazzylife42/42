/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:36:57 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:13:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Fake No type")
{
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    setType("Fake No Type");
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
    _type = src.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
        _type = rhs.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "~Destructor called for " << getType() << " ~"<< RST << std::endl;
}

// Getter
std::string WrongAnimal::getType(void) const
{
    return _type;
}

// Setter
void WrongAnimal::setType(std::string type)
{
    _type = type;
}

//method

void	WrongAnimal::makeSound(void)
{
	std::cout << YEL "* Unrecognized Wronganimal sound , but sounds sus 🤫 *" RST << std::endl;
}