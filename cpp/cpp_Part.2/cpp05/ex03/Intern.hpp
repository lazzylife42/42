/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:25:43 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 18:55:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    // Public Constructors and Destructor
    Intern();
    Intern(Intern const &src);
    Intern& operator=(const Intern &rhs);
    ~Intern();
    // Exception
    class	NoValidFormException : public std::exception
		{
			virtual const char	*what() const throw();	
		};
    // Public Methods
    AForm* makeForm(const std::string &formName, const std::string &formTarget);

protected:
    // Protected members
    AForm* createShrubberyCreationForm(const std::string &formTarget);
    AForm* createRobotomyRequestForm(const std::string &formTarget);
    AForm* createPresidentialPardonForm(const std::string &formTarget);
};

#endif