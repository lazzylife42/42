/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:35:27 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 18:37:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << CLR;

	std::string	formName;
	std::string	formTarget;

	std::cout << WHT "INIT BUREAUCRAT" << RST << std::endl;
	Bureaucrat	john("John", 138);
	Bureaucrat	bill("Bill", 46);
	Bureaucrat	kyle("kyle", 6);

	std::cout << std::endl << std::endl;
	std::cout << WHT "INIT INTERN" << RST << std::endl;
	Intern		slave;

	std::cout << std::endl << std::endl;
	std::cout << WHT "INTERN: MAKEFORM (INVALID VALUES)" << RST << std::endl;
	formName = "invalid";
	formTarget = "invalid";
	try
	{
		slave.makeForm(formName, formTarget);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << WHT "INTERN: MAKEFORM (EMPTY VALUES)" << RST << std::endl;
	formName = "";
	formTarget = "";
	try
	{
		slave.makeForm(formName, formTarget);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << WHT "INTERN: MAKEFORM (SHRUBBERY)" << RST << std::endl;
	formName = "shrubbery creation";
	formTarget = "SCF";
	AForm*	scf = slave.makeForm(formName, formTarget);

	std::cout << std::endl << std::endl;
	std::cout << WHT "INTERN: MAKEFORM (ROBOTOMY)" << RST << std::endl;
	formName = "robotomy request";
	formTarget = "RRF";
	AForm*	rrf = slave.makeForm(formName, formTarget);

	std::cout << std::endl << std::endl;
	std::cout << WHT "INTERN: MAKEFORM (PRESIDENTIAL)" << RST << std::endl;
	formName = "presidential pardon";
	formTarget = "PPF";
	AForm*	ppf = slave.makeForm(formName, formTarget);

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: EXECUTEFORM (NO SIGNED)" << RST << std::endl;
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: SIGNS IT" << RST << std::endl;
	john.signForm(*scf);
	bill.signForm(*rrf);
	kyle.signForm(*ppf);

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: EXECUTEFORM (BAD GRADE)" << RST << std::endl;
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: INCREMENT GRADE" << RST << std::endl;
	john.incrementGrade();
	bill.incrementGrade();
	kyle.incrementGrade();

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: RE-SIGNS (ERROR, ALREADY SIGNED)" << RST << std::endl;
	john.signForm(*scf);
	bill.signForm(*rrf);
	kyle.signForm(*ppf);

	std::cout << std::endl << std::endl;
	std::cout << WHT "BUREAUCRATS: EXECUTEFORM (FROM INTERN'S FORMS)" << RST << std::endl;
	john.executeForm(*scf);
	bill.executeForm(*rrf);
	kyle.executeForm(*ppf);

	std::cout << std::endl << std::endl;
	std::cout << WHT "DESTRUCTORS (INTERN'S FORMS)" << RST << std::endl;

	delete scf;
	delete rrf;
	delete ppf;

	std::cout << std::endl << std::endl;
	std::cout << WHT "DESTRUCTORS (DEFAULT)" << RST << std::endl;
	return (0);
}