/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:48:41 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:09:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
    setType("WrongDog");
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

WrongDog::WrongDog(const WrongDog &src) : WrongAnimal(src)
{
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog &rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return *this;
}

WrongDog::~WrongDog()
{
    std::cout << RED << "~Destructor called for " << getType() << " ~" << RST << std::endl;
}

void WrongDog::makeSound(void)
{
    std::cout << WHT "🦍 Wrong woaf 🦍 sus 🤫" RST << std::endl;
}
