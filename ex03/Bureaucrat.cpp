/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:41:39 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/30 12:49:01 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat const	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::gradeDown(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
