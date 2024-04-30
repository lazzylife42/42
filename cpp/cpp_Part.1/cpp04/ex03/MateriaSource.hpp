/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:49:37 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 17:47:59 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <string>
#include "color.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
public:
    // Constructors and Destructor
    MateriaSource();
    MateriaSource(MateriaSource const &src);
    MateriaSource& operator=(const MateriaSource &rhs);
    ~MateriaSource();
    // Public Methods
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

private:
    // Private members
    AMateria*	_table[4];
};

#endif