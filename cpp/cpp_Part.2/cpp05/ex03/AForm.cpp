/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:05:58 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:32:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors & Destructor
AForm::AForm(void)
	: _signed(false), _name("AForm"), _grade_to_sign(DEF_TO_SIGN), _grade_to_exec(DEF_TO_EXEC), _target("Default")
{
	std::cout << GRN << "Default AForm Constructor called for " << _name << RST << std::endl;
	return;
}

AForm::AForm(const std::string &name, unsigned int grade_to_sign, unsigned int grade_to_exec)
	:_signed(false), _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	std::cout << GRN "Parametric AForm constructor called for " << _name << RST << std::endl;
	std::cout << _name << RST << std::endl;
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();
	return;
}

AForm::AForm(const AForm& src)
	:_signed(src._signed), _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _target("DefaultTarget")
{
	std::cout << GRN "Copy AForm constructor called for " << _name <<  RST << std::endl;
	return;
}

AForm& AForm::operator=(const AForm& rhs)
{
	(void)rhs;
	return *this;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm Destructor called for " << _name << RST << std::endl;
	return;
}

// Getters & Setters
const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _signed;
}

unsigned int AForm::getToSign() const
{
	return _grade_to_sign;
}

unsigned int AForm::getToExec() const
{
	return _grade_to_exec;
}
const std::string& AForm::getTarget() const
{
	return _target;
}

void	AForm::setTarget(const std::string &target)
{
	_target = target;
}

void	AForm::setIsSigned(bool isSigned)
{
	_signed = isSigned;
}

// Exceptions
const char*	AForm::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high ! (from AForm)" RST);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low ! (from AForm)" RST);
}

// Members Functions
void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= _grade_to_sign)
	{
		_signed = true;
		std::cout << BLU << src.getName();
		std::cout << " just signed the Aform " << _name;
		std::cout << " !" RST << std::endl;
	}
	else
	{
		std::cout << MAG "The grade of " << src.getGrade();
		std::cout << " is too low to sign the Aform " << _name;
		std::cout << ". (Need grade minimum " << _grade_to_exec;
		std::cout << " for this Aform !)" << RST << std::endl;
	}
}

// Functions
std::ostream&	operator<<(std::ostream &os, const AForm &src)
{
	std::string bl;
	(src.getIsSigned() == false) ? bl = "false" : bl = "true";

	std::cout << WHT "AForm's name:\t\t" << src.getName() << std::endl;
	std::cout <<  "AForm is signed:\t\t" << bl << std::endl;
	std::cout <<  "AForm min. sign grade:\t" << src.getToSign() << std::endl;
	std::cout <<  "AForm min. exec grade:\t" << src.getToExec() << RST << std::endl;
	return (os);
}
