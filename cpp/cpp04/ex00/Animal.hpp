/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:15:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 00:09:17 by smonte-e         ###   ########.fr       */
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

class Animal
{
public:
    // Public Constructors and Destructor
    Animal();
    Animal(Animal const &src);
    Animal& operator=(const Animal &rhs);
    virtual ~Animal();
    // Public Methods
    void setType(std::string type);
    std::string getType(void) const;
    virtual void makeSound(void);

protected:
    // Private members
    std::string _type;
};

#endif