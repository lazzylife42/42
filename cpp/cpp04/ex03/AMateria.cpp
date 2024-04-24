/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:28:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 19:13:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AMateria.hpp"


AMateria::AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

AMateria::~AMateria()
{
}

const std::string& AMateria::getType() const
{
    if (this != nullptr)
        return _type;
    else
	{
        static const std::string emptyString;
        return emptyString;
    }
}


void	AMateria::use(ICharacter &target)
{
	std::cout << "Default attack (no type) on " << target.getName() << std::endl;
}