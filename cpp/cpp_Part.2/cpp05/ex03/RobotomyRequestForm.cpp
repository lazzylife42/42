/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:12:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 17:12:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RRF_form", 72, 45)
{
	this->setTarget("RRF_target");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RRF_form", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src.getName(), src.getToSign(), src.getToExec())
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->setTarget(src.getTarget());
	this->setIsSigned(src.getIsSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw Bureaucrat::FormNotSigned();
    if (executor.getGrade() > this->getToExec())
        throw AForm::GradeTooLowException();

    std::cout << YEL "* Drilling noises (brrrrrrr) *" RST << std::endl;
    if ((getRandomNumber() % 2 == 0))
    {
        std::cout << GRN "ROBOTOMY SUCCESSFULL ! The target " << this->getTarget();
        std::cout << GRN " has been robotomized." RST << std::endl;
    }
    else
    {
        std::cout << MAG "ROBOTOMY FAILED ! The target " << this->getTarget();
        std::cout << MAG " hasn't been robotomized, better luck next time !" RST << std::endl;
    }
}

int getRandomNumber()
{
    std::ifstream urandom("/dev/urandom", std::ios::binary);
    if (!urandom)
        return -1;
    char buffer[4];
    urandom.read(buffer, 4);
    urandom.close();
	
    unsigned int randomNumber = static_cast<unsigned char>(buffer[0]) |
                                 (static_cast<unsigned char>(buffer[1]) << 8) |
                                 (static_cast<unsigned char>(buffer[2]) << 16) |
                                 (static_cast<unsigned char>(buffer[3]) << 24);

    return static_cast<int>(randomNumber);
}