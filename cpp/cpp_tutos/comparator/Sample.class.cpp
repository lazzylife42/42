/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:33:34 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 14:59:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(int v)
{
    std::cout << GRN << "contructor called" << RST << std::endl;
    this->_foo = 0;
    std::cout << "this->publicFoo: " << this->_foo << std::endl;

    return;
}

Sample::~Sample(void)
{
    std::cout << RED << "Destructor called" << RST << std::endl;
    return;
}

int Sample::getFoo(void) const
{
    return this->_foo;
}

int Sample::compare(Sample* other) const
{
    if (this->_foo < other->getFoo())
        return -1;
    else if (this->_foo > other->getFoo())
        return 1;
    return 0;
}
