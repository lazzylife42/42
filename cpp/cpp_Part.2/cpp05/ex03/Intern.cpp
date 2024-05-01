/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:27:45 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 19:02:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "color.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    (void)src;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    typedef AForm* (Intern::* FormCreatorFunc)(const std::string&);
    FormCreatorFunc formCreators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    const std::string formNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

    for (size_t i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            AForm* result = (this->*formCreators[i])(formTarget);

            std::cout << YEL "Intern creates " << formName;
            std::cout << " with target " << formTarget;
            std::cout << RST << std::endl;
            return result;
        }
    }
    throw NoValidFormException();
}


AForm* Intern::createShrubberyCreationForm(const std::string& formTarget)
{
    return new ShrubberyCreationForm(formTarget);
}

AForm* Intern::createRobotomyRequestForm(const std::string& formTarget)
{
    return new RobotomyRequestForm(formTarget);
}

AForm* Intern::createPresidentialPardonForm(const std::string& formTarget)
{
    return new PresidentialPardonForm(formTarget);
}

const char* Intern::NoValidFormException::what() const throw()
{
    return (RED "Invalid Form ! (from Intern)" RST);
}

