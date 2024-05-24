/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:20 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/24 14:03:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <vector>
#include "color.hpp"

class	NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return (RED "Element not found !" RST);
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int element)
{
	typename T::iterator it = std::find(container.begin(), container.end(), element);

	if (it == container.end())
		throw (NotFoundException());
	return (it);
}

#endif