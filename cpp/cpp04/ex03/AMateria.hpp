/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:43:25 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:30:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include "color.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
    // Constructors and Destructor
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &src);
    AMateria& operator=(const AMateria &src);
    // Virtual Methods
    virtual ~AMateria();
    virtual void use(ICharacter& target) = 0;
    virtual AMateria* clone() const = 0;
    // Public Methods
    std::string const & getType() const;
protected:
    // Protected members
    std::string _type;
};

#endif