/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:29:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:38:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    // Public Constructors and Destructor
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
    virtual ~ShrubberyCreationForm();
    // Public Methods
    void execute(const Bureaucrat &executor) const;

protected:
    // Protected members
};

void aTree(std::ofstream& outfile);

#endif
