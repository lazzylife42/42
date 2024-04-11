/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:32:13 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/11 10:54:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include <iostream>

class Weapon
{
public:
    // Public members
    Weapon(std::string type);
    ~Weapon();

    const std::string& getType() const;
    void setType(const std::string& newType);
    
private:
    // Private members
    std::string type;
};

#endif