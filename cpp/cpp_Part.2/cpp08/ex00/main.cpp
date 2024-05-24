/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:01 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/24 14:39:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void tryEasyFind(T &container, int value)
{
    try
    {
        typename T::iterator it = easyfind(container, value);
        std::cout << GRN "Element " << "\'" << value << "\' " << GRN "found !"
                  << RST " At pos [" << std::distance(container.begin(), it) << "]" << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cout << e.what() << RED " \'" << value << "\'" RST << std::endl;
    }
}


int	main(void)
{
	std::cout << CLR;

	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i + 1);
	std::cout << std::endl;
	
	tryEasyFind(vec, 3);
	std::cout << std::endl;
	
	tryEasyFind(vec, 6);
	std::cout << std::endl;

	
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i + 1);
	std::cout << std::endl;

	tryEasyFind(lst, 1);
	std::cout << std::endl;

    tryEasyFind(lst, -2);
    std::cout << std::endl;
    
    fill(begin(lst), end(lst), -2);
	tryEasyFind(lst, -2);

	std::cout << std::endl;
	
	return (0);
}