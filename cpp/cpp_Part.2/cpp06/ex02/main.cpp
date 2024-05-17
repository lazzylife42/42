/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:02:18 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/17 18:54:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.hpp"



Base*	generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
        std::cout << BLU "Type :\t A " RST << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
        std::cout << CYA "Type :\t B " RST << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
        std::cout << MAG "Type :\t C " RST << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << BLU "Type :\tA " RST << std::endl;
	}
	catch (const std::bad_cast &e) { ; }
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << CYA "Type :\tB " RST << std::endl;
	}
	catch (const std::bad_cast &e) { ; }
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << MAG "Type :\tC " RST << std::endl;
	}
	catch (const std::bad_cast &e) { ; }
}

int main(void)
{
	std::cout << CLR;
    srand(static_cast<unsigned int>(time(0)));

    Base* instances[INSTANCES];

    for (int i = 0; i < INSTANCES; i++)
        instances[i] = generate();
    
    std::cout << WHT "----Identify pointer----" RST<< std::endl << std::endl;
	for (int i = 0; i < INSTANCES; ++i)
		identify(instances[i]);
	std::cout << std::endl;

    std::cout << MAG "----Identify reference----" RST<< std::endl << std::endl;
	for (int i = 0; i < INSTANCES; ++i)
		identify(*instances[i]);
	std::cout << std::endl;

	for (int i = 0; i < INSTANCES; ++i)
		delete  instances[i];

    return 0;

}