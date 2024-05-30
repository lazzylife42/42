/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormatCheck.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:56:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/30 14:47:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATCHECK_HPP
# define FORMATCHECK_HPP

#include <string>
#include <iostream>
#include "color.hpp"

class FormatCheck
{
public:
    // Check & find Methods
    static bool isValidDate(const std::string &input);
    static bool isValidPrice(const std::string &input);
    static bool isValidFile(const std::string &filePath);
    static const std::string& findNearestDate(const std::map<std::string, float> &db, const std::string &input);
    
private:
    // Private Members
    FormatCheck();
    FormatCheck(FormatCheck const &src);
    FormatCheck& operator=(const FormatCheck &rhs);
    ~FormatCheck();
    
};

#endif
