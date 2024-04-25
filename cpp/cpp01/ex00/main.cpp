/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:09:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 10:11:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie b;
    b.nameZombie("Booba");
    b.announce();
    Zombie* r = newZombie("Rohff");
    r->announce();
    randomChump("Kaaris");
    delete r;
    return 0;
}