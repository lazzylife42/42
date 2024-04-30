/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:54:03 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 19:07:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
		_table[i] = NULL;
    std::cout << GRN << "Constructor called for MateriaSource" << RST << std::endl;
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (!src._table[i])
			_table[i] = NULL;
		else
			_table[i] = src._table[i]->clone();
	}
    std::cout << GRN << "Copy constructor called for MateriaSource" << RST << std::endl;
}

// Assignment Operator Overload
MateriaSource& MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
	    for (int i = 0; i < 4; i++)
	    {
            if (_table[i])
                delete _table[i];
            if (!rhs._table[i])
                _table[i] = NULL;
            else
                _table[i] = rhs._table[i]->clone();
        }
        std::cout << GRN << "Assignment operator called for MateriaSource" << RST << std::endl;
    }
    return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
	{
		if (_table[i])
			delete _table[i];
	}
    std::cout << RED << "~Destructor called for MateriaSource~" << RST << std::endl;
}

// Public Methods
void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
    {
        std::cout << RED "Cannot learn null materia for MateriaSource" RST << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!_table[i])
        {
            _table[i] = materia;
            std::cout << "Learning materia " << materia->getType() << " for MateriaSource" << std::endl;
            return;
        }
    }
    std::cout << MAG "Inventory is full, cannot learn materia for MateriaSource" RST << std::endl;
}


AMateria* MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_table[i] && _table[i]->getType() == type)
        {
            return _table[i]->clone();
        }
    }
    std::cout << "No materia of type " << type << " found in MateriaSource" << std::endl;
    return nullptr;
}

