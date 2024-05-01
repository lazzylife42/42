/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:29:42 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 17:13:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "color.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    // Public Constructors and Destructor
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
    virtual ~RobotomyRequestForm();
    // Public Methods
    void execute(const Bureaucrat &executor) const;

protected:
    // Protected members
};

int getRandomNumber();

#endif