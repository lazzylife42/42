/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:10:08 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 01:26:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void)
{
    std::cout << CLR;
    std::cout << YEL "///// TEST AVEC 2 ANIMAUX /////" << std::endl << std::endl;
    std::cout << YEL "// CONSTRUCTEURS D'ANIMAUX" << std::endl;
    Animal a1;
    Animal a2(a1);
    std::cout << YEL "// SON DES ANIMAUX" << std::endl;
    a1.makeSound();
    a2.makeSound();

    std::cout << std::endl << MAG "///// TEST AVEC 2 CHATS /////" RST << std::endl << std::endl;
    std::cout << MAG "// CONSTRUCTEURS DE CHATS" << std::endl;
    Cat c1;
    Cat c2(c1);
    std::cout << MAG "// SON DES CHATS" << std::endl;
    c1.makeSound();
    c2.makeSound();

    std::cout << std::endl << BLU "///// TEST AVEC 2 CHIENS /////" RST << std::endl << std::endl;
    std::cout << BLU "// CONSTRUCTEURS DE CHIENS" << std::endl;
    Dog d1;
    Dog d2(d1);
    std::cout << BLU "// SON DES CHIENS" << std::endl;
    d1.makeSound();
    d2.makeSound();

    for (int i = 0; i < 3; i++)
        std::cout << std::endl;

    std::cout << YEL "///// TEST AVEC 2 WRONG ANIMAUX /////" << std::endl << std::endl;
    std::cout << YEL "// CONSTRUCTEURS DE WRONG ANIMAUX" << std::endl;
    WrongAnimal wa1;
    WrongAnimal wa2(wa1);
    std::cout << YEL "// SON DES WRONG ANIMAUX" << std::endl;
    wa1.makeSound();
    wa2.makeSound();

    std::cout << std::endl << CYA "///// TEST AVEC 2 WRONG CHATS /////" RST << std::endl << std::endl;
    std::cout << CYA "// CONSTRUCTEURS DE WRONG CHATS" << std::endl;
    WrongCat wc1;
    WrongCat wc2(wc1);
    std::cout << CYA "// SON DES WRONG CHATS" << std::endl;
    wc1.makeSound();
    wc2.makeSound();

    std::cout << std::endl << WHT "///// TEST AVEC 2 WRONG CHIENS /////" RST << std::endl << std::endl;
    std::cout << WHT "// CONSTRUCTEURS DE WRONG CHIENS" << std::endl;
    WrongDog wd1;
    WrongDog wd2(wd1);
    std::cout << WHT "// SON DES WRONG CHIENS" << std::endl;
    wd1.makeSound();
    wd2.makeSound();

    std::cout << std::endl;
    std::cout << std::endl << RED "///// TOUS LES DESTRUCTEURS /////" RST << std::endl;
    std::cout << std::endl;

    return 0;
}