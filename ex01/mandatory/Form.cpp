/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:18:39 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 12:37:25 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("XXX"), _signed(false), _gradeSign(5), _gradeExecute(5)
{
	std::cout << "Form default constructor called" << std::endl;
} 

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, const int gradeSign, const int gradeExecute) :
_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (_gradeSign > 150 || _gradeExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		std::cout << "Form " << _name << " constructor called" << std::endl; 
	}
		
}

Form::Form(const Form &a) : _name(a._name), _signed(a._signed),
_gradeSign(a._gradeSign), _gradeExecute(a._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &a)
{
	if (this != &a)
	{
		_signed = a._signed;
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getSigned() const
{
	return (_signed);
}

const int	Form::getGradeSign() const
{
	return (_gradeSign);
}

const int	Form::getGradeExecute() const
{
	return (_gradeExecute);
}

void		Form::beSigned(Bureaucrat &a)
{
	if (a.getGrade() <= _gradeSign)
	{
		_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}	
}

std::ostream& operator<<(std::ostream &o, const Form &a)
{
	o << "Form " << a.getName() << " data:" << std::endl;
	o << "Signed?: " << a.getSigned() << std::endl;
	o << "Grade sign: " << a.getGradeSign() << std::endl;
	o << "Grade execute: " << a.getGradeExecute() << std::endl;
	return (o);
}
