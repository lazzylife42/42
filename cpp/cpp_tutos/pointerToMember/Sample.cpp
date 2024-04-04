/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:34:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 15:56:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

Sample::Sample(void) : foo(0)
{
    std::cout << GRN << "Constructor called" << RST << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << RED << "Destructor called" << RST << std::endl;
    return;
}

void    Sample::bar(void) const
{
    std::cout << CYA << "Member func bar called" << RST << std::endl;
    return;
}
