/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:15:49 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 10:55:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << GRN << "contructor called" << RST << std::endl;

	this->publicFoo = 0;
	std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample(void)
{
	std::cout << RED << "Destructor called" << RST << std::endl;
	return;
}

void    Sample::publicBar(void) const
{
	std::cout << "Member func publicBar called" << std::endl;
	return;
}

void    Sample::_privateBar(void) const
{
	std::cout << "Member func _privateBar called" << std::endl;
	return;
}