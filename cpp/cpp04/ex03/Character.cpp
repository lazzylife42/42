/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:03:38 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 19:23:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// Default Constructor
Character::Character()
{
    _name = "No name";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
    std::cout << GRN << "Default Character Constructor called for " << this->getName() << RST << std::endl;
}

// Constructor with name
Character::Character(const std::string &name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
    std::cout << GRN << "Named Character Constructor called for " << this->getName() << RST << std::endl;
}

// Copy Constructor
Character::Character(const Character &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = src._inventory[i]->clone();
	}
	_name = src._name;
    std::cout << GRN << "Copy constructor called for " << src.getName() << RST << std::endl;
}

// Assignment Operator Overload
Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (rhs._inventory[i] == NULL)
                _inventory[i] = NULL;
            else
                _inventory[i] = rhs._inventory[i]->clone();
        }
        _name = rhs._name;
        std::cout << GRN << "Assignment operator called for " << rhs.getName() << RST << std::endl;
        return (*this);
    }
    return *this;
}

// Destructor
Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
		if (_inventory[i])
			delete _inventory[i];
    }
    std::cout << RED << "~Destructor called for " << this->getName() << " ~" << RST << std::endl;
}

// Getter
const std::string& Character::getName() const
{
    if (this != nullptr)
        return _name;
    else
	{
        static const std::string emptyString;
        return emptyString;
    }
}

// Public Method
void	Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			std::cout << YEL << _name << ": equipped " << materia->getType() << RST << std::endl;
			return ;
		}
	}
	std::cout << YEL << _name << ": no space left for " << materia->getType() << RST << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << MAG << _name <<  ": no Materia found at index " << idx << RST << std::endl;
		return ;
	}
	if (_inventory[idx])
	{
		std::cout << MAG << _name << ": remove from his inventory " << _inventory[idx]->getType() << RST << std::endl;
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << MAG << _name << ": no Materia found at index " << idx << RST << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
        std::cout << MAG << _name << ": invalid Materia index or Materia not found at index " << idx << RST << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}


AMateria*	Character::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
	{
		std::cout << MAG << _name << ": no Materia found at index " << idx << RST << std::endl;
		return (NULL);
	}
	if (_inventory[idx])
		return (_inventory[idx]);
	std::cout << MAG << _name << ": no Materia found at index " << idx << RST << std::endl;
	return (NULL);
}