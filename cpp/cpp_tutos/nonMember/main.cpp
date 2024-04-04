/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:45 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 15:28:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

void    f0(void)
{
    Sample instance;

    std::cout << "Num of instance : " << YEL << Sample::getNbInst() << RST << std::endl;
    return;
}

void    f1(void)
{
    Sample instance;

    std::cout << "Num of instance : " << BLU << Sample::getNbInst() << RST << std::endl;
    f0();

    return;
}

int main()
{
    std::cout << "Num of instance : " << CYA << Sample::getNbInst() << RST << std::endl;
    f1();
    std::cout << "Num of instance : " << CYA << Sample::getNbInst() << RST << std::endl;

    return 0;
}
