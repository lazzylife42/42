/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:30 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 15:17:43 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

Sample::Sample(void)
{
    std::cout << GRN << "Constructor Called" << RST << std::endl;
    Sample::_nbInst +=1;
    return;
}

Sample::~Sample(void)
{
    std::cout << RED << "Destructor Called" << RST << std::endl;
    Sample::_nbInst -=1;
    return;
}

int Sample::getNbInst(void)
{
    return Sample::_nbInst;
}

int Sample::_nbInst = 0;