/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:37:40 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:19:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
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

class WrongAnimal
{
public:
    // Public Constructors and Destructor
    WrongAnimal();
    WrongAnimal(WrongAnimal const &src);
    WrongAnimal& operator=(const WrongAnimal &rhs);
    virtual ~WrongAnimal();
    // Public Methods
    void setType(std::string type);
    std::string getType(void) const;
    virtual void makeSound(void);

protected:
    // Private members
    std::string _type;
};

#endif