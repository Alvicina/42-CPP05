/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:05:09 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 12:42:38 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Alejandro;
		std::cout << Alejandro;

		Form		IRPF("IRPF", 5, 5);
		std::cout << IRPF;

		Bureaucrat Jose("Jose", 7);
		Jose.incrementGrade();
		std::cout << Jose;

		Jose.signForm(IRPF);

		//Alejandro.decrementGrade();
		//Jose.incrementGrade();

		Bureaucrat Mauro("Mauro", 150);
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