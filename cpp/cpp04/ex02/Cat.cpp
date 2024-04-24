/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:18:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:40:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Cat.hpp"

Cat::Cat() : aAnimal()
{
    setType("Cat");
    std::cout << GRN << "Constructor called for " << getType() << RST << std::endl;
}

Cat::Cat(const Cat &src) : aAnimal(src)
{
    std::cout << GRN << "Copy Constructor called for " << getType() << RST << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
        aAnimal::operator=(rhs);
    return *this;
}

Cat::~Cat()
{
    std::cout << RED << "~Destructor called for " << getType() << " ~" << RST << std::endl;
}

void Cat::makeSound(void)
{
    std::cout << MAG "🐈 miaou 🐈" RST << std::endl;
}
