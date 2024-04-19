/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:36:41 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 12:44:44 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << getName() << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "Bureaucrat " << getName() << " appeared" << std::endl;
	}	
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) : _name(a._name), _grade(a._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a)
{
	if (this != &a)
	{
		if (a._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (a._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = a._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return (o);
}

void	Bureaucrat::signForm(Form &a)
{
	try
	{
		a.beSigned(*this);
		std::cout << "Bureaucrat " << getName() << " signed Form " << a.getName(); 
		std::cout << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << getName() << " could not signed Form " << a.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}