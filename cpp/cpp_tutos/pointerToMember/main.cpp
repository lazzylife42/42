/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:44 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 15:58:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

int main()
{
    Sample instance;
    Sample* instancep = &instance;

    int     Sample::* p = NULL;
    void    (Sample:: * f)(void) const;

    p = &Sample::foo;

    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instance.*p = 21;
    std::cout << "Value of member foo: " << instance.foo << std::endl;
    instancep->*p = 42;
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    f = &Sample::bar;

    (instance.*f)();
    (instancep->*f)();

    return 0;
}
