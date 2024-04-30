/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/13 20:50:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << GRN << "Default constructor called" << RST << std::endl;
    return;
}

Fixed::Fixed(Fixed const &src) : _value(src._value)
{
    std::cout << GRN << "Copy constructor called" << RST << std::endl;
    *this = src;
    return;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    std::cout << MAG << "Copy assignment operator called" << RST << std::endl;
    if (this != &rhs)
        this->_value =rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}

// Getter
int Fixed::getRawBits(void) const
{
    std::cout << BLU << "getRawBits member function called" << RST << std::endl;
    return (this->_value);
}

// Setter
void Fixed::setRawBits(int raw)
{
    std::cout << BLU << "setRawBits member function called" << RST << std::endl;
    this->_value = raw;
}
