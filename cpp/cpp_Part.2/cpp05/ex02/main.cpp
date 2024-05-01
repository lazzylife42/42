/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:35:27 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:52:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << CLR;
	std::cout << CYA "Initialisation des Bureaucrats" RST << std::endl;
	Bureaucrat	john("John", 138);
	Bureaucrat	bill("Bill", 46);
	Bureaucrat	kyle("kyle", 6);

	std::cout << std::endl;
	std::cout << WHT "Initialisation des Forms" RST << std::endl;
	ShrubberyCreationForm	scf("scf_target");
	RobotomyRequestForm		rrf("rrf_target");
	PresidentialPardonForm	ppf("ppf_target");

	std::cout << std::endl;
	std::cout << WHT "Try to Execute" RST << std::endl;
	john.executeForm(scf);
	bill.executeForm(rrf);
	kyle.executeForm(ppf);

	std::cout << std::endl;
	std::cout << WHT "Try to Sign" RST << std::endl;
	john.signForm(scf);
	bill.signForm(rrf);
	kyle.signForm(ppf);

	std::cout << std::endl;
	std::cout << WHT "Try to Execute without good level" RST << std::endl;
	john.executeForm(scf);
	bill.executeForm(rrf);
	kyle.executeForm(ppf);

	std::cout << std::endl;
	std::cout << WHT "Increment execution grade" RST << std::endl;
	john.incrementGrade();
	bill.incrementGrade();
	kyle.incrementGrade();

	std::cout << std::endl;
	std::cout << WHT "Try to Sign" RST << std::endl;
	john.signForm(scf);
	bill.signForm(rrf);
	kyle.signForm(ppf);

	std::cout << std::endl;
	std::cout << WHT "Try to Execute" RST << std::endl;
	john.executeForm(scf);
	for (int i = 0; i <= 10; i++)
		bill.executeForm(rrf);
	kyle.executeForm(ppf);

	std::cout << std::endl << std::endl;
	return (0);
}