/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:34:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 19:19:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"
#define CLR "\033[2J\033[1;1H"

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // Public Constructors and Destructor
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& src);
    ScavTrap& operator=(const ScavTrap &rhs);
    ~ScavTrap();

    // Public Methods
    // void attack(const std::string& target);
    // void takeDamage(unsigned int amount);
    // void beRepaired(unsigned int amount);
    void guardGate(void);
};

#endif