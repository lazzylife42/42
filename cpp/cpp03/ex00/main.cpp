/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/18 19:22:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
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
    return 0;
}