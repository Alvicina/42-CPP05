/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:09 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/15 18:49:24 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Alejandro;
		std::cout << Alejandro;

		Bureaucrat Jose("Jose", 3);
		Jose.incrementGrade();
		std::cout << Jose;

		//Alejandro.decrementGrade();
		//Jose.incrementGrade();

		Bureaucrat Mauro("Mauro", 151);
		std::cout << Mauro;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;	
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}