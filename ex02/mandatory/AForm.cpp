/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:18:39 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 12:37:25 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("XXX"), _signed(false), _gradeSign(5), _gradeExecute(5)
{
	std::cout << "AForm default constructor called" << std::endl;
} 

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeSign, const int gradeExecute) :
_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (_gradeSign > 150 || _gradeExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "AForm " << _name << " constructor called" << std::endl; 
	}
		
}

AForm::AForm(const AForm &a) : _name(a._name), _signed(a._signed),
_gradeSign(a._gradeSign), _gradeExecute(a._gradeExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &a)
{
	if (this != &a)
	{
		_signed = a._signed;
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (_name);
}

bool		AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeSign() const
{
	return (_gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (_gradeExecute);
}

void		AForm::beSigned(Bureaucrat &a)
{
	if (a.getGrade() <= _gradeSign)
	{
		_signed = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}	
}

std::ostream& operator<<(std::ostream &o, const AForm &a)
{
	o << "AForm " << a.getName() << " data:" << std::endl;
	o << "Signed?: " << a.getSigned() << std::endl;
	o << "Grade sign: " << a.getGradeSign() << std::endl;
	o << "Grade execute: " << a.getGradeExecute() << std::endl;
	return (o);
}
/*
void AForm::checkForm(Bureaucrat const &executor) const
{
	if (_gradeExecute <= executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (_signed == false)
		throw AForm::NotSignedException();
}*/
