/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:01:36 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:46:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor & Destructor
Bureaucrat::Bureaucrat() : _name("None"), _grade(150)
{
	std::cout << GRN "Default Bureaucrat constructor called for " << _name << RST << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	std::cout << GRN "Parametric Bureaucrat constructor called for " << _name << RST << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << GRN "Copy Bureaucrat constructor called" <<  RST << std::endl;
	*this = src;
	return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED "Bureaucrat Destructor called for " << _name << RST << std::endl;
	return;
}

// Getter & Setter
const std::string& Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

// Exceptions
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high ! (Max 1)." RST);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low ! (Min 150)." RST);
}

const char*	Bureaucrat::FormNotSigned::what() const throw()
{
	return (RED "The Form must be signed to execute it !" RST);
}

// Merbers Functions
void	Bureaucrat::incrementGrade()
{
	if ((_grade) - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		_grade--;
		std::cout << BLU << _name << " got promoted ! He is now at grade " << _grade <<  "." RST << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if ((_grade) + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		_grade++;
		std::cout << MAG << _name << " got downgraded ! He is now at grade " << _grade << "." RST << std::endl;
	}
}

// Function
std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << BLU << src.getName() << WHT ", bureaucrat grade " << src.getGrade() << "." RST;
	return (os);
}

void	Bureaucrat::signForm(AForm &src)
{
	if (src.getIsSigned() == true)
	{
		std::cout << BLU "Bureaucrat " << _name;
		std::cout << " couldn't sign Form " << src.getName();
		std::cout << " because it is already signed." RST << std::endl;
		return ;
	}
	else
	{
		if (_grade <= src.getToSign())
			src.beSigned(*this);
		else
		{
			std::cout << MAG "The grade of " << _name;
			std::cout << " is too low to sign the form " << src.getName() << std::endl;
			std::cout << "(Need grade minimum " << src.getToSign();
			std::cout << " for this form !)" << RST << std::endl;
		}
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << BLU "Bureacrat "  << this->getName();
		std::cout <<  " executed " << form.getName();
		std::cout << RST << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << std::endl;
	}
}