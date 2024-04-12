/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:15:51 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 14:07:14 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
    complaints_[0] = &Harl::debug;
    complaints_[1] = &Harl::info;
    complaints_[2] = &Harl::warning;
    complaints_[3] = &Harl::error;
    return;
}

Harl::~Harl(void)
{
    std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}

void    Harl::debug(void)
{
    std::cout << MAG << "DEBUG   : " << RST "I love having extra bacon for "
    " my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
    << std::endl;
    return;
}

void    Harl::info(void)
{
    std::cout << BLU << "INFO    : " << RST "I cannot believe adding extra "
    "bacon costs more money. You didn’t put enough bacon in my burger! If you"
    " did, I wouldn’t be asking for more!" << std::endl;
    return;
}

void    Harl::warning(void)
{
    std::cout << YEL << "WARNING : " << RST "I think I deserve to have some "
    "extra bacon for free. I’ve been coming for years whereas you started "
    "working here since last month." << std::endl;
    return;   
}

void    Harl::error(void)
{
    std::cout << RED << "ERROR   : " << RST "This is unacceptable!"
    " I want to speak to the manager now." << std::endl;
    return;   
}

std::string levels_[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::complain(const std::string level)
{
    for (int i = 0; i < 4; ++i)
        if (level == levels_[i])
            (this->*(complaints_[i]))();
            return;
    std::cout << RED << "Unknown level: " << level << RST << std::endl;
}