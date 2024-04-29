/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:35:27 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/29 21:00:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << CLR;

	Bureaucrat	b1("John", 2);
	Form		f1("Contract", 1, 1);

	std::cout << std::endl;;
	tryCreate();

	std::cout << std::endl;;
	std::cout << "BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	std::cout << std::endl;;
	std::cout << "FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	std::cout << "## TRIES TO SIGN" << std::endl;
	b1.signForm(f1);

	std::cout << std::endl;;
	std::cout << "BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	std::cout << std::endl;;
	std::cout << "FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	std::cout << "## PROMOTION" << std::endl;
	tryIncrement(&b1);
	
	std::cout << std::endl;;
	std::cout << "## TRIES TO SIGN" << std::endl;
	b1.signForm(f1);
	
	std::cout << std::endl;;
	std::cout << "BUREAUCRAT <<" << std::endl;
	std::cout << b1 << std::endl;

	std::cout << std::endl;;
	std::cout << "FORM <<" << std::endl;
	std::cout << f1 << std::endl;

	std::cout << std::endl;;
	return (0);	
}