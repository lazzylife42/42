/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:09:07 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/29 20:57:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# define DEF_TO_SIGN 1
# define DEF_TO_EXEC 1

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form
{
public:
	// Constructors and destructor
	Form();
	Form(const std::string &name, unsigned int grade_to_sign, unsigned int grade_to_exec);
	Form(const Form& src);
	Form& operator=(const Form& rhs);
	~Form();
	// Members Functions
	const std::string &getName() const;
	bool getIsSigned() const;
	unsigned int getToSign() const;
	unsigned int getToExec() const;
	void beSigned(const Bureaucrat &src);
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
	bool _signed;
	const std::string _name;
	const unsigned int _grade_to_sign;
	const unsigned int _grade_to_exec;
	
};

std::ostream&	operator<<(std::ostream &os, const Form &src);
void	tryIncrement(Bureaucrat *b);
void	tryCreate(void);

#endif