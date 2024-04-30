/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:09:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 10:33:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* horde = zombieHorde(42, "Kaaris");

    if (horde != nullptr)
    {
        for (int i = 0; i < 42; ++i)
            horde[i].announce();
            
        delete[] horde;
    }
    else
        std::cout << RED << "La création de la horde de zombies a échoué." << RST << std::endl;

    return 0;
}
