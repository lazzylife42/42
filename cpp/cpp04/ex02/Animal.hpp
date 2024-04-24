/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:15:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:38:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"
#define CLR "\033[2J\033[1;1H"

#include <string>
#include "Brain.hpp"

class aAnimal
{
public:
    // Public Constructors and Destructor
    aAnimal();
    aAnimal(aAnimal const &src);
    aAnimal& operator=(const aAnimal &rhs);
    virtual ~aAnimal();
    // Public Methods
    void setType(std::string type);
    std::string getType(void) const;
    Brain* getBrain() const;
    virtual void makeSound(void) = 0;

protected:
    // Private members
    std::string _type;
    Brain* _brain;
};

#endif