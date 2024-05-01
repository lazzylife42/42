/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:36:43 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/01 16:05:50 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <string>
#include <iostream>
#include "color.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	// Constructors and destructor
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();
	// Members Functions
	const std::string &getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &src);
	void executeForm(const AForm &form);
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
	
	class	FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

private:
	// Private members
	std::string		_name;
	unsigned int	_grade;
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src);

#endif