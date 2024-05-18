/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:13:03 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/18 19:42:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;    
    return;
}

template <typename T>
const T& min(const T &x, const T &y)
{
    return ((x < y)? x : y);    
}

template <typename T>
const T& max(const T &x, const T &y)
{
    return ((x > y)? x : y);    
}