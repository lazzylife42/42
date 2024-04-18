/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/18 17:37:19 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("ClapTrap");

    claptrap.attack("Enemy");
    claptrap.takeDamage(30);
    claptrap.beRepaired(20);

    return 0;
}