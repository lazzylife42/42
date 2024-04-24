/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:42:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:08:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    setType("WrongCat");
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << RED << "~Destructor called for " << getType() << " ~" << RST << std::endl;
}

void WrongCat::makeSound(void)
{
    std::cout << CYA "🐂 Wrong miaou 🐂 sus 🤫" RST << std::endl;
}
