/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:36:43 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/29 19:02:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"
#define CLR "\033[2J\033[3J\033[H"

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <string>
#include <iostream>

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
	std::string		_name;
	unsigned int	_grade;
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &src);
void	tryIncrement(Bureaucrat *b);
void	tryDecrement(Bureaucrat *b);

#endif