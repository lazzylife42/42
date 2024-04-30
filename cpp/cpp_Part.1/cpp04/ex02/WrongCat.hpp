/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:40:18 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:19:56 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
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

class WrongCat : virtual public WrongAnimal
{
public:
    // Public Constructors and Destructor
    WrongCat();
    WrongCat(WrongCat const &src);
    WrongCat& operator=(const WrongCat &rhs);
    virtual ~WrongCat();
    // Public Methods
    virtual void makeSound(void);

protected:
    // Protected members
};

#endif