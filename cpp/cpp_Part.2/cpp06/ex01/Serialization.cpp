/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:58 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 15:41:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Serialization.hpp"

// Constructors & Desctructor
Serialization::Serialization() {}
Serialization::Serialization(Serialization const &src) { (void)src; }
Serialization& Serialization::operator=(const Serialization &rhs) { (void)rhs; return (*this); }
Serialization::~Serialization() {}

uintptr_t Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}