/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:25:25 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/18 17:29:55 by smonte-e         ###   ########.fr       */
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

#include <iostream>
#include <cstring>

class ClapTrap
{
public:
	// Constructors and destructor
	ClapTrap(std::string name);
	~ClapTrap();
	// Copy constructor and assignation operator overload
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& rhs);
	// Public member
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	// Private members
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attack;
};

#endif