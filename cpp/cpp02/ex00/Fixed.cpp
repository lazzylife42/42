/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 18:30:59 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << GRN << "Default constructor called" << RST << std::endl;
    return;
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
    return;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        this->_value =rhs.getValue();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}

// Getter
int Fixed::getValue() const
{
    return _value;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

// Setter
void Fixed::setValue(int value)
{
    _value = value;
}
