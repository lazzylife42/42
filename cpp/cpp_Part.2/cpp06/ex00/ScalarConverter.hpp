/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:50:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/03 14:05:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include "color.hpp"

class ScalarConverter
{
public:
	// Members Functions
	static void	convert(const std::string& input);

private:
	// Constructor & Destructor
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();

	// Statics Functions
	static bool	isChar(const std::string& input);
	static bool	isInt(const std::string& input);
	static bool	isFloat(const std::string& input);
	static bool	isDouble(const std::string& input);
	// static bool isOther(const std::string& input);

	static char		toChar(const std::string& input);
	static int		toInt(const std::string& input);
	static float	toFloat(const std::string& input);
	static double	toDouble(const std::string& input);
	// static void		toOther(const std::string& input);
};



#endif