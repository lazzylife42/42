/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:10:08 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/24 10:12:20 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << CLR;
    std::cout << YEL "///// TEST AVEC 2 ANIMAUX /////" << std::endl << std::endl;
    std::cout << YEL "// CONSTRUCTEURS D'ANIMAUX" << std::endl;
    Animal a1;
    Animal a2(a1);
    std::cout << YEL "// IDÉES DES ANIMAUX" << std::endl;
    a1.getBrain()->setIdeas("Idea 1 for Animal 1", 0);
    a1.getBrain()->setIdeas("Idea 2 for Animal 1", 1);
    a2.getBrain()->setIdeas("Idea 1 for Animal 2", 0);
    a2.getBrain()->setIdeas("Idea 2 for Animal 2", 1);
    std::cout << "Ideas for Animal 1: " << a1.getBrain()->getIdeas(0) << ", " << a1.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Ideas for Animal 2: " << a2.getBrain()->getIdeas(0) << ", " << a2.getBrain()->getIdeas(1) << std::endl;

    std::cout << std::endl << MAG "///// TEST AVEC 2 CHATS /////" RST << std::endl << std::endl;
    std::cout << MAG "// CONSTRUCTEURS DE CHATS" << std::endl;
    Cat c1;
    Cat c2(c1);
    std::cout << MAG "// IDÉES DES CHATS" << std::endl;
    c1.getBrain()->setIdeas("Idea 1 for Cat 1", 0);
    c1.getBrain()->setIdeas("Idea 2 for Cat 1", 1);
    c2.getBrain()->setIdeas("Idea 1 for Cat 2", 0);
    c2.getBrain()->setIdeas("Idea 2 for Cat 2", 1);
    std::cout << "Ideas for Cat 1: " << c1.getBrain()->getIdeas(0) << ", " << c1.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Ideas for Cat 2: " << c2.getBrain()->getIdeas(0) << ", " << c2.getBrain()->getIdeas(1) << std::endl;

    std::cout << std::endl << BLU "///// TEST AVEC 2 CHIENS /////" RST << std::endl << std::endl;
    std::cout << BLU "// CONSTRUCTEURS DE CHIENS" << std::endl;
    Dog d1;
    Dog d2(d1);
    std::cout << BLU "// IDÉES DES CHIENS" << std::endl;
    d1.getBrain()->setIdeas("Idea 1 for Dog 1", 0);
    d1.getBrain()->setIdeas("Idea 2 for Dog 1", 1);
    d2.getBrain()->setIdeas("Idea 1 for Dog 2", 0);
    d2.getBrain()->setIdeas("Idea 2 for Dog 2", 1);
    std::cout << "Ideas for Dog 1: " << d1.getBrain()->getIdeas(0) << ", " << d1.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Ideas for Dog 2: " << d2.getBrain()->getIdeas(0) << ", " << d2.getBrain()->getIdeas(1) << std::endl;

    for (int i = 0; i < 3; i++)
        std::cout << std::endl;

    std::cout << std::endl << BLU "///// LEAKS TESTS /////" RST << std::endl << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << std::endl;
    std::cout << std::endl << RED "///// TOUS LES DESTRUCTEURS /////" RST << std::endl;
    std::cout << std::endl;
    delete j;
    delete i;

    return 0;
}