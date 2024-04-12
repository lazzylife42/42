/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:11:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 10:40:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceString(const std::string& line, const std::string& find, const std::string& replace)
{
    std::string result;
    size_t pos = 0;
    size_t found_pos;
    
    while ((found_pos = line.find(find, pos)) != std::string::npos)
    {
        result += line.substr(pos, found_pos - pos);
        result += replace;
        pos = found_pos + find.length();
    }
    
    result += line.substr(pos);
    return result;
}