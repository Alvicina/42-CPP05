/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:56:09 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/17 11:10:27 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl;
		std::cout << "----------Instantiate classes-------------" << std::endl;
		Bureaucrat Mauro("Mauro", 150);
		std::cout << Mauro << std::endl;

		Bureaucrat Jose("Jose", 4);
		std::cout << Jose << std::endl;

		//AForm Javi;
		ShrubberyCreationForm	form1("Shrubber");
		RobotomyRequestForm		form2("Jesus");
		PresidentialPardonForm	form3("Alejandro");
		std::cout << std::endl;
	
		std::cout << "----------ShrubberyCreationForm-------------" << std::endl;
		Mauro.signAForm(form1);
		Jose.signAForm(form1);
		Mauro.executeForm(form1);
		Jose.executeForm(form1);
		Jose.executeForm(form2);
		std::cout << std::endl;
		
		std::cout << "----------RobotomyRequestForm-------------" << std::endl;
		Jose.signAForm(form2);
		Jose.executeForm(form2);
		Jose.executeForm(form2);
		Jose.executeForm(form2);
		Jose.executeForm(form2);
		std::cout << std::endl;
		
		std::cout << "----------PresidentialPardonForm-------------" << std::endl;
		Jose.signAForm(form3);
		Jose.executeForm(form3);
		std::cout << std::endl;

		std::cout << "----------Destructors-------------" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat could not be created because " << e.what();
		std::cout << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat could not be created because " << e.what();
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}