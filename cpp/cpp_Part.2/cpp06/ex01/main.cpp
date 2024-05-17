/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:41:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 18:37:56 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Serialization.hpp"
#include <string>

int main(void)
{
    Data* d1 = new Data;
    Data* d2 = new Data;
    Data* d3 = new Data;

    int intValue = 42;
    std::string stringValue = "Salut man ca va?";
    bool boolValue = true;

    d1->data = reinterpret_cast<void*>(&intValue);
    d2->data = reinterpret_cast<void*>(&stringValue);
    d3->data = reinterpret_cast<void*>(&boolValue);

    uintptr_t result1 = Serialization::serialize(d1);
    uintptr_t result2 = Serialization::serialize(d2);
    uintptr_t result3 = Serialization::serialize(d3);

    std::cout << std::endl;
    std::cout << WHT "===========Serialized===========|================" RST << std::endl;
    std::cout << BLU "Serialized value 1 (int):     \t|" << WHT << result1 << RST << std::endl;
    std::cout << CYA "Serialized value 2 (string):  \t|" << WHT << result2 << RST << std::endl;
    std::cout << MAG "Serialized value 3 (bool):    \t|" << WHT << result3 << RST << std::endl << std::endl;

    // Example of deserialization
    Data* d4 = Serialization::deserialize(result1);
    Data* d5 = Serialization::deserialize(result2);
    Data* d6 = Serialization::deserialize(result3);
    
    std::cout << WHT "===========Deserialized=========|================" RST << std::endl;
    std::cout << BLU "Deserialized int value:   \t|" << WHT << *reinterpret_cast<int*>(d4->data) << RST << std::endl;
    std::cout << CYA "Deserialized string value:\t|" << WHT << *reinterpret_cast<std::string*>(d5->data) << RST << std::endl;
    std::cout << MAG "Deserialized bool value:  \t|" << WHT << *reinterpret_cast<bool*>(d6->data) << RST << std::endl << std::endl;

    delete d1;
    delete d2;
    delete d3;

    return 0;
}