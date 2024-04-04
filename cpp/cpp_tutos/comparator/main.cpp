/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:23 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 14:55:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int main()
{
    Sample i1(42);
    Sample i2(42);

    if (&i1 == &i1)
        std::cout << "i1 and i1 are physically equal" << std::endl;
    else
        std::cout << "i1 and i1 are not physically equal" << std::endl;

    if (&i1 == &i2)
        std::cout << "i1 and i2 are physically equal" << std::endl;
    else
        std::cout << "i1 and i2 are not physically equal" << std::endl;

    if (i1.compare(&i1) == 0)
        std::cout << "i1 and i1 are structurally equal" << std::endl;
    else
        std::cout << "i1 and i1 are not structurally equal" << std::endl;

    if (i1.compare(&i2) == 0)
        std::cout << "i1 and i2 are structurally equal" << std::endl;
    else
        std::cout << "i1 and i2 are not structurally equal" << std::endl;
    
    return 0;
}
