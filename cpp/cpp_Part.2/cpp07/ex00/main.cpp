/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:29:37 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/18 19:47:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    std::cout << std::endl << BLU "===========INT===========" RST << std::endl;
    std::cout << BLU "a    = " RST << a << BLU ", b    = " RST << b << RST << std::endl;
    ::swap( a, b );
    std::cout << BLU "After swap" RST << std::endl;
    std::cout << BLU "a    = " RST << a << BLU ", b    = " RST << b << RST << std::endl;
    std::cout << BLU "min( a, b )    = " RST << ::min( a, b ) << std::endl;
    std::cout << BLU "max( a, b )    = " RST << ::max( a, b ) << std::endl << std::endl;
    
    std::cout << CYA "==========string=========" RST << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << CYA "c = " RST << c << CYA ", d = " RST << d << RST << std::endl;
    ::swap(c, d);
    std::cout << CYA "After swap" RST << std::endl;
    std::cout << CYA "c = " RST << c << CYA ", d = " RST << d << RST << std::endl;
    std::cout << CYA "min( c, d )    = " RST << ::min( c, d ) << std::endl;
    std::cout << CYA "max( c, d )    = " RST << ::max( c, d ) << std::endl << std::endl;
    return 0;
}