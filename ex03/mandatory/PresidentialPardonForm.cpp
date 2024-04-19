/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:10:53 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:26 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default constructor for PresidentialPardonForm called";
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Constructor for PresidentialPardonForm called with param";
	std::cout << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for PresidentialPardonForm called";
	std::cout << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) :
AForm(a.getName(), a.getGradeSign(), a.getGradeExecute()), _target(a._target)
{
	std::cout << "Copy constructor for PresidentialPardonForm called";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	(void) a;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getGradeExecute() <= executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (getSigned() == false)
		throw AForm::NotSignedException();
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " executed AForm " << getName(); 
		std::cout << std::endl;
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox";
		std::cout << std::endl;
	}
}
