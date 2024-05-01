/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:38:42 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:38:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("SCF_form", 145, 137)
{
	this->setTarget("SCF_target");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("SCF_form", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getToExec())
		throw AForm::GradeTooLowException();
	
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	outfile (filename);
	aTree(outfile);
	outfile.close();
}

void aTree(std::ofstream& outfile)
{
    outfile << "           *\n";
    outfile << "          ***\n";
    outfile << "         *****\n";
    outfile << "        *******\n";
    outfile << "       *********\n";
    outfile << "      ***********\n";
    outfile << "     *************\n";
    outfile << "    ***************\n";
    outfile << "   *****************\n";
    outfile << "  *******************\n";
    outfile << " *********************\n";
    outfile << "           |||\n";
}
