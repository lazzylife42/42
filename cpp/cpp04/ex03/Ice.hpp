/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:02:06 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:24:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include <string>
#include "color.hpp"
#include "AMateria.hpp"

class Ice : virtual public AMateria 
{
public:
    // Public Constructors and Destructor
    Ice();
    Ice(Ice const &src);
    Ice& operator=(const Ice &rhs);
    ~Ice();
    // Public Methods
    void use(ICharacter& target);
    Ice* clone() const;

protected:
    // Protected members
};

#endif