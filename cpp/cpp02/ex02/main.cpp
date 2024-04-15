/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:05:03 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/15 16:45:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << YEL << "Comparaison avec b:" << std::endl;
	std::cout << BLU << "a = " << RST << a << BLU << " | ";
	std::cout << BLU << "b = " << RST << b << std::endl; 
	
    std::cout << YEL << "Test a > b : " << RST << (a > b) << std::endl;
    std::cout << YEL << "Test a < b : " << RST << (a < b) << std::endl;
    std::cout << YEL << "Test a >= b: " << RST << (a >= b) << std::endl;
    std::cout << YEL << "Test a <= b: " << RST << (a <= b) << std::endl;
    std::cout << YEL << "Test a == b: " << RST << (a == b) << std::endl;
    std::cout << YEL << "Test a != b: " << RST << (a != b) << std::endl;
	std::cout << std::endl;
	
    std::cout << CYA << "Opérations arithmétiques:" << std::endl;
	std::cout << BLU << "a = " << RST << a << BLU << " | ";
	std::cout << BLU << "b = " << RST << b << std::endl;
	
    Fixed c = a + b;
    std::cout << CYA << "Test a + b: " << RST << c << std::endl;
    c = a - b;
    std::cout << CYA << "Test a - b: " << RST << c << std::endl;
    c = a * b;
    std::cout << CYA << "Test a * b: " << RST << c << std::endl;
    c = a / b;
    std::cout << CYA << "Test a / b: " << RST << c << std::endl;
	std::cout << std::endl;

    std::cout << MAG << "Min/Max:" << std::endl;
    Fixed min_result = Fixed::min(a, b);
    Fixed max_result = Fixed::max(a, b);
    std::cout << MAG << "Test Min(a, b): " << RST << min_result << std::endl;
    std::cout << MAG << "Test Max(a, b): " << RST << max_result << std::endl;
	std::cout << std::endl;
	
    return (0);
}
