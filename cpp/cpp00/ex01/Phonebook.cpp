/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:55:28 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 18:03:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
    return;
}

Phonebook::~Phonebook(void)
{
    std::cout << RED << "Destructor called" << RST << std::endl;
    return;
}