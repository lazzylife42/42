/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:47:38 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 19:25:03 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) 
{
    std::cout << RST;
    // Creating a character
    Character* character = new Character("Kaaris");

    // Creating some materia
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    // Learning materia
    character->equip(ice);
    character->equip(cure);

    // Using materia
    ICharacter* target = new Character("Booba");
    std::cout << CYA << "Using materia..." << RST << std::endl;
    character->use(0, *target);
    character->use(1, *target);

    // Creating a materia source
    IMateriaSource* source = new MateriaSource();

    // Learning a new materia
    source->learnMateria(ice->clone());

    // Creating a new ice materia from the materia source
    AMateria* newIce = source->createMateria("CIROC");
    if (newIce)
    {
        std::cout << GRN << "Successfully created new ice materia: " << newIce->getType() << RST << std::endl;
        character->equip(newIce);
    }
    else
        std::cout << RED << "Failed to create new ice materia" << RST << std::endl;

    // Using the cloned materia
    std::cout << CYA << "Using cloned materia..." << RST << std::endl;
    character->use(2, *target);

    // Testing error cases
    std::cout << MAG << "Testing error cases..." << RST << std::endl;
    character->use(10, *target); // Trying to use a non-existent materia
    character->unequip(10);      // Trying to unequip a non-existent slot
    character->equip(nullptr);   // Trying to equip a nullptr materia

    // Cleaning up
    delete target;
    delete character;
    delete source;

    return 0;
}

