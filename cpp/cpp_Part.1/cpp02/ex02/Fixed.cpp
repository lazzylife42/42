/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/15 18:39:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    // std::cout << GRN << "Default constructor called" << RST << std::endl;
    return;
}

Fixed::Fixed(Fixed const &src) : _value(src._value)
{
    // std::cout << GRN << "Copy constructor called" << RST << std::endl;
    return;
}

Fixed::Fixed(const int val)
{
    // std::cout << GRN << "Int constructor called" << RST << std::endl;
    this->_value = val * (1 << this->_bits);
}


Fixed::Fixed(const float val)
{
    // std::cout << GRN << "Constructeur float appelé" << RST << std::endl;
    this->_value = roundf(val * (1 << this->_bits));
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    // std::cout << MAG << "Copy assignment operator called" << RST << std::endl;
    if (this != &rhs)
        this->_value =rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << RED << "~Destructor called~" << RST << std::endl;
    return;
}

// Getter
int Fixed::getRawBits(void) const
{
    // std::cout << BLU << "getRawBits member function called" << RST << std::endl;
    return (this->_value);
}

// Setter
void Fixed::setRawBits(int raw)
{
    // std::cout << BLU << "setRawBits member function called" << RST << std::endl;
    this->_value = raw;
}

// Member Functions
float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_value) / (1 << this->_bits));
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

// Compare operators
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

// Arithmetic Operators
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

// Incrementation/Decrementation Operators
Fixed& Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed& Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

// Min/Max
Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}
