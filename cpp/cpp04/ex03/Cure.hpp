/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:04:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:24:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include <string>
#include "color.hpp"
#include "AMateria.hpp"

class Cure : virtual public AMateria
{
public:
    // Public Constructors and Destructor
    Cure();
    Cure(Cure const &src);
    Cure& operator=(const Cure &rhs);
    ~Cure();
    // Public Methods
    void use(ICharacter& target);
    Cure* clone() const;

protected:
    // Protected members
};

#endif