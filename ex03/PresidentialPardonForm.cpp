/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:15:22 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/30 12:32:19 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form::Form("PresidentialPardonForm", 25, 5), _target("null") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form::Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): Form::Form(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

Form	*PresidentialPardonForm::makeForm(Form *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (form);
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
