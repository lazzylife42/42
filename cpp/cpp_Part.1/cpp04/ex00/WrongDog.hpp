/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:48:04 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:20:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_H
# define WRONGDOG_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"
#define CLR "\033[2J\033[1;1H"

#include "WrongAnimal.hpp"

class WrongDog : virtual public WrongAnimal
{
public:
    // Public Constructors and Destructor
    WrongDog();
    WrongDog(WrongDog const &src);
    WrongDog& operator=(const WrongDog &rhs);
    virtual ~WrongDog();
    // Public Methods
    virtual void makeSound(void);

protected:
    // Protected members
};
#endif