/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/23 22:06:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << CLR;
    std::cout << std::endl << BLU "\t\t\tCLAPTRAP TEST" RST << std::endl << std::endl;
    ClapTrap claptrap("Kaaris");

    for (int i = 0; i < 9; i++)
        claptrap.attack("Booba");
    claptrap.takeDamage(9);
    claptrap.beRepaired(20);
    claptrap.attack("Booba");
    claptrap.attack("Booba");
    claptrap.beRepaired(20);
    claptrap.takeDamage(100);
    claptrap.attack("Booba");
    claptrap.beRepaired(20);

    std::cout << std::endl << CYA "\t\t\tSCAVTRAP TESTS" RST << std::endl << std::endl;
    ScavTrap scavtrap("Booba");

    scavtrap.guardGate();
    for (int i = 0; i < 48; i++)
        scavtrap.attack("Kaaris");
    scavtrap.takeDamage(9);
    scavtrap.beRepaired(20);
    scavtrap.attack("Kaaris");
    scavtrap.attack("Kaaris");
    scavtrap.beRepaired(20);
    scavtrap.takeDamage(100);
    scavtrap.attack("Kaaris");
    scavtrap.beRepaired(20);
    scavtrap.takeDamage(100);
    scavtrap.attack("Kaaris");
    scavtrap.guardGate();
    return 0;
}