/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/13 21:44:40 by smonte-e         ###   ########.fr       */
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
    return;
}

Fixed::Fixed(const int val)
{
    std::cout << GRN << "Int constructor called" << RST << std::endl;
    this->_value = val * (1 << this->_bits);
}


Fixed::Fixed(const float val)
{
    std::cout << GRN << "Float constructor called" << RST << std::endl;
    this->_value = roundf(val * (1 << this->_bits));
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

// Member Functions
float Fixed::toFloat(void) const
{
    return (this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value / (1 << this->_bits));
}

// Functions
std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}