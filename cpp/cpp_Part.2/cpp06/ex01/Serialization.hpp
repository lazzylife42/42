/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:25:17 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 16:48:14 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "Data.hpp"

class Serialization
{
public:
    // Public Methods
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

protected:
    // Protected members
    Serialization();
    Serialization(Serialization const &src);
    Serialization& operator=(const Serialization &rhs);
    ~Serialization();
};

#endif