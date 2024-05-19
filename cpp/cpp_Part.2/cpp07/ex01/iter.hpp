/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:52:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/19 19:15:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T, typename U, typename V>
void iter(T* addr, U len, V func)
{
    for (std::size_t i = 0; i < static_cast<std::size_t>(len); ++i)
        func(addr[i]);
}

template<typename T>
void printNum(T num)
{
    std::cout << "[" << num << "]" << std::endl; 
}