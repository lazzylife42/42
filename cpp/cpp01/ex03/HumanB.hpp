/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:42:39 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 10:58:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    // Public members
    HumanB(std::string name);
    ~HumanB();
    void attack(void) const;
    void setWeapon(const Weapon& newWeapon);
    
private:
    // Private members
    std::string name;
    Weapon weapon;
};

#endif