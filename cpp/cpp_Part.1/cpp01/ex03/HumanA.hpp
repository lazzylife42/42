/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:39:13 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 11:56:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
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

class HumanA
{
public:
    // Public members
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack(void) const;
    
private:
    // Private members
    std::string _name;
    Weapon& _weapon;
};

#endif