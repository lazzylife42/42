/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:05:19 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 00:11:56 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# define DEF_TO_SIGN 1
# define DEF_TO_EXEC 1

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	// Constructors and destructor
	AForm();
	AForm(const std::string &name, unsigned int grade_to_sign, unsigned int grade_to_exec);
	AForm(const AForm& src);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();
	// Members Functions
	const std::string &getName() const;
	bool getIsSigned() const;
	unsigned int getToSign() const;
	unsigned int getToExec() const;
	void beSigned(const Bureaucrat &src);
	void setTarget(const std::string &target);
	void setIsSigned(bool isSigned);
	// Exception Class
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
private:
	// Private members
	bool				_signed;
	const std::string	_name;
	const unsigned int	_grade_to_sign;
	const unsigned int	_grade_to_exec;
	std::string			_target;
	
};

std::ostream&	operator<<(std::ostream &os, const AForm &src);

#endif