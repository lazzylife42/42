/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:50:27 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/23 18:00:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <algorithm>
#include <exception>
#include <iostream>

template<typename T>
class easyfind
{
    public:
        easyfind(T firstPram, int secondPraram)
        {
            typename T::iterator it = std::find(firstPram.begin(), firstPram.end(), secondPraram);
            if (it == firstPram.end())
                throw std::runtime_error("Value not found in the container");
            else
                std::cout << "Value found: " << *it << std::endl;
        }

        easyfind(easyfind const &src)
        {
            // implémentez la logique de copie si nécessaire
        }

        easyfind& operator=(const easyfind &rhs)
        {
            if (this != &rhs)
            {
                // implémentez la logique d'assignation si nécessaire
            }
            return *this;
        }

        ~easyfind()
        {
            // implémentez la logique de destruction si nécessaire
        }
        
    private:
        easyfind()
        {
            // implémentez la logique du constructeur par défaut si nécessaire
        }
};

#endif
