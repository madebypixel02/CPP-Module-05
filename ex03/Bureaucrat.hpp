/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:41:32 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/30 12:45:35 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string 		_name;
		int					_grade;
	public:
		/* Constructors & Destructors */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		/* Basic Operators */
		Bureaucrat const	&operator=(Bureaucrat const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		int const			&getGrade(void) const;

		/* Main Member Functions */
		void	gradeUp(void);
		void	gradeDown(void);
		void	signForm(Form &form);
		void	executeForm(Form const &form);

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);
