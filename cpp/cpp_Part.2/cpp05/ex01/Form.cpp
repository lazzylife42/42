/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:17:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 11:24:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors & Destructor
Form::Form(void)
	: _signed(false), _name("None"), _grade_to_sign(DEF_TO_SIGN), _grade_to_exec(DEF_TO_EXEC)
{
	std::cout << GRN << "Default Form Constructor called for " << _name << RST << std::endl;
	return;
}

Form::Form(const std::string &name, unsigned int grade_to_sign, unsigned int grade_to_exec)
	:_signed(false), _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	std::cout << GRN "Parametric Form constructor called for " << _name << RST << std::endl;
	return;
}

Form::Form(const Form& src)
	:_signed(src._signed), _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec)
{
	std::cout << GRN "Copy Form constructor called for " << _name <<  RST << std::endl;
	return;
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Form::~Form(void)
{
	std::cout << RED << "Form Destructor called for " << _name << RST << std::endl;
	return;
}

// Getters & Setters
const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _signed;
}

unsigned int Form::getToSign() const
{
	return _grade_to_sign;
}

unsigned int Form::getToExec() const
{
	return _grade_to_exec;
}

// Members Functions
void Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() >= _grade_to_sign)
	{
		_signed = true;
		std::cout << BLU << src.getName();
		std::cout << " just signed the form " << _name;
		std::cout << " !" RST << std::endl;
	}
	else
	{
		std::cout << MAG "The grade of " << src.getGrade();
		std::cout << " is too low to sign the form " << _name;
		std::cout << ". (Need grade minimum " << _grade_to_exec;
		std::cout << " for this form !)" << RST << std::endl;
	}
}

// Functions
std::ostream&	operator<<(std::ostream &os, const Form &src)
{
	std::string bl;
	(src.getIsSigned() == false) ? bl = "false" : bl = "true";

	std::cout << WHT "Form's name:\t\t" << src.getName() << std::endl;
	std::cout <<  "Form is signed:\t\t" << bl << std::endl;
	std::cout <<  "Form min. sign grade:\t" << src.getToSign() << std::endl;
	std::cout <<  "Form min. exec grade:\t" << src.getToExec() << RST << std::endl;
	return (os);
}

