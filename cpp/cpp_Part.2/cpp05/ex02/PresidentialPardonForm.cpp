/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:58:16 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:22:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PPF_form", 25, 5)
{
	this->setTarget("PPF_target");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PPF_form", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() >= this->getToExec())
		throw AForm::GradeTooLowException();

	std::cout << BLU "The target " << this->getTarget();
	std::cout << " has been pardoned by Zaphod Beeblebrox." RST << std::endl;
}