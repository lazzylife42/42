/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:53 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/02 20:24:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

// Constructors & Desctructor
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

// Members Functions
