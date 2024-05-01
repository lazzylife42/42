/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:29:01 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:05:57 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "color.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    // Public Constructors and Destructor
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();
    // Public Methods
    void execute(const Bureaucrat &executor) const;

protected:
    // Protected members
};

#endif