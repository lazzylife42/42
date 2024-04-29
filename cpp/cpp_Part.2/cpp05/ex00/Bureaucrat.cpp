/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:01:36 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/29 19:54:47 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	std::cout << GRN "Bureaucrat Destructor called for " << _name << RST << std::endl;
	return;
}

// Getter & Setter
const std::string& Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
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

void	tryIncrement(Bureaucrat *b)
{
	std::cout << "Try to increment the grade of bureaucrat " << b->getName() << std::endl;
	try
	{
		b->incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << RED "Exception caught: " << e.what() << RST << std::endl;
	}
}

void	tryDecrement(Bureaucrat *b)
{
	std::cout << "Try to decrement the grade of bureaucrat "<< b->getName() << std::endl;
	try
	{
		b->decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED "Exception caught: " << e.what() << RST << std::endl;
	}
}