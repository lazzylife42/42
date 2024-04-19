/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:25 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/18 20:39:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"
#define CLR "\033[2J\033[1;1H"

#include <iostream>
#include <cstring>

class ClapTrap
{
public:
    // Public Constructors and Destructor
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ClapTrap& operator=(const ClapTrap &rhs);
    ~ClapTrap();

    // Public Methods
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters and Setters
    std::string getName(void) const;
    unsigned int getHealth(void) const;
    unsigned int getEnergy(void) const;
    unsigned int getAttack(void) const;
    void setHealth(unsigned int health);
    void setEnergy(unsigned int energy);
    void setAttack(unsigned int attack);

protected:
    // Protected members
    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _attack;
};

#endif