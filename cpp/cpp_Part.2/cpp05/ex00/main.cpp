/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:35:27 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/29 19:03:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << CLR;

	Bureaucrat	b1("John", 1);
	Bureaucrat	b2;

	std::cout << std::endl;
	std::cout << "Printing infos with surcharged operator <<" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	std::cout << std::endl;
	tryIncrement(&b1);
	
	std::cout << std::endl;
	tryDecrement(&b2);

	std::cout << std::endl;
	tryIncrement(&b2);
	
	std::cout << std::endl;
	tryDecrement(&b1);

	std::cout << std::endl;
	return (0);
}