/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:09:30 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:32:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
public:
    // Constructors and Destructor
    Character();
    Character(const std::string &name);
    Character(const Character &src);
    Character& operator=(const Character &src);
    ~Character();
    // Getter and Setter
    std::string const &getName() const;
    AMateria*	getMateria(int idx) const;
    // Public Methods
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    
protected:
    // Protected members
    std::string _name;
    AMateria*   _inventory[4];
};

#endif