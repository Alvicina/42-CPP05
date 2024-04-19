/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:05:33 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/17 11:26:18 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default constructor for ShrubberyCreationForm called";
	std::cout << std::endl;
} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Constructor for ShrubberyCreationForm called with param";
	std::cout << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for ShrubberyCreationForm called";
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) :
AForm(a.getName(), a.getGradeSign(), a.getGradeExecute()), _target(a._target)
{
	std::cout << "Copy constructor for ShrubberyCreationForm called";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	(void) a;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getGradeExecute() <= executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (getSigned() == false)
		throw AForm::NotSignedException();
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " executed AForm " << getName(); 
		std::cout << std::endl;
		std::ofstream	file(_target + "_shrubery");
		file << "			 A			    " << std::endl;
		file << "	  |      |        |      " << std::endl;
		file << "	  B	     C        D		" << std::endl;
		file << "   |  |   |   |   |  |  |   " << std::endl;
		file << "   E  F   G   H   I  J  K   " << std::endl;
		file << "		   |	   |		    " << std::endl;
		file << "		   L	   M		    " << std::endl;
	}
}