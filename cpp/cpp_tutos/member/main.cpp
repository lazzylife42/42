/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:37 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/03 16:05:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

int main(void)
{
    Sample instance;
    instance.bar();
    instance.foo = 42;
    
    std::cout << "foo = " << instance.foo << std::endl; 
    return 0;
}