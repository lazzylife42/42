/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:04 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 10:53:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int  main()
{
    Sample instance;

    instance.publicFoo = 42;
    std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
    instance.publicBar();
    
    return 0;
}
