/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:09:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/10 18:09:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie z;
    z.nameZombie("Booba");
    z.announce();
    z.randomChump("Kaaris");
    
    return 0;
}