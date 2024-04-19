/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/19 12:21:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
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

    std::cout << std::endl << YEL "\t\t\tFRAGTRAP TESTS" RST << std::endl << std::endl;
    FragTrap fragtrap("Rohff");

    for (int i = 0; i < 98; i++)
        fragtrap.attack("Booba");
     fragtrap.highFivesGuys();
    fragtrap.takeDamage(10);
    fragtrap.beRepaired(20);
    fragtrap.attack("Booba");
    fragtrap.attack("Booba");
    fragtrap.beRepaired(20);
    fragtrap.takeDamage(1000);
    fragtrap.attack("Booba");
    fragtrap.beRepaired(20);
    fragtrap.highFivesGuys();
    return 0;
}