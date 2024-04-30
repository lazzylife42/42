/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:11:23 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 18:30:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include <cstring>
#include <iostream>


class Harl
{
public:
    // Public members
    Harl();
    ~Harl();
    void (Harl::*complaints_[4])();
    void complain(std::string level);
    
private:
    // Private members
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
};

#endif
