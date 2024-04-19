/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:59:37 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/17 13:31:22 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &a)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = a;
}

Intern& Intern::operator=(const Intern &a)
{
	(void) a;
	return (*this);
}

static AForm* makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string nameForm, std::string target)
{
	size_t	i = 0;

	std::string forms[3] = {
		"Shrubbery creation",
		"Robotomy request",
		"Presidential pardon",
	};

	AForm* (*newForm[3]) (std::string target) = {
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm,
		&makePresidentialPardonForm,
	};
	while (i < 3)
	{
		if (nameForm == forms[i])
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return newForm[i](target);
		}
		i++;
	}
	std::cout << "Intern could not create " << nameForm;
	std::cout << " because it does not exist" << std::endl;
	return (nullptr);
}