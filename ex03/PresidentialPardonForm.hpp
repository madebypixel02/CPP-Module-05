/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:15 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/30 12:31:37 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form
{
	private:
		std::string	_target;
	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);

		/* Basic Operators */
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &copy);

		/* Main Member Functions */
		void		beExecuted(Bureaucrat const &bureaucrat) const;
		static Form	*makeForm(Form *form, std::string const &type, std::string const &target);

		/* Getters & Setters */
		std::string const	&getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);
