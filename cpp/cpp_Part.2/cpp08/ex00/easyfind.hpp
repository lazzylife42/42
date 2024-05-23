/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:20 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/23 17:53:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include "color.hpp"
#include "easyfind.tpp"

template<typename T>
class easyfind
{
    public:
        easyfind(T firstPram, int secondPraram);
        easyfind(easyfind const &src);
        easyfind& operator=(const easyfind &rhs);        
        ~easyfind();
        
    private:
        easyfind();
};


#endif