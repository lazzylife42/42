/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:04 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/03 19:05:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
    this->foo = 42;
    std::cout << "this->foo" << this->foo << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::bar(void)
{
	std::cout << "The func \'bar\' called" << std::endl;
}