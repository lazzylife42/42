/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:46:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 09:57:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GRN << "Constructor called for Brain" << RST << std::endl;
    return;
}

Brain::Brain(const Brain &src)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    std::cout << GRN << "Copy Constructor called for Brain" << RST << std::endl;
    return;
}

Brain& Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    }
    std::cout << GRN << "Assignment operator called for Brain" << RST << std::endl;
    return *this;
}
Brain::~Brain()
{
    std::cout << RED << "~Destructor called for Brain ~" << RST << std::endl;
    return;
}

void Brain::setIdeas(std::string const newIdea, unsigned int n)
{
    if (n >= 100)
    {
        std::cerr << RED "Index out of bounds!" RST << std::endl;
        return;
    }
    _ideas[n] = newIdea;
}

std::string Brain::getIdeas(unsigned int n) const
{
    if (n >= 100)
    {
        std::cerr << RED "Index out of bounds!" RST << std::endl;
        return "";
    }
    return _ideas[n];
}
