/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:56:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 12:35:39 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;	
			
	public:
		Form();
		~Form();
		Form(std::string name, const int gradeSign, const int gradeExecute);
		Form(const Form &a);
		Form& operator=(const Form &a);
		std::string	getName() const;
		bool		getSigned() const;
		const int	getGradeSign() const;
		const int	getGradeExecute() const;
		void		beSigned(Bureaucrat &a);
		

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
		
};

std::ostream& operator<<(std::ostream &o, const Form &a);

#endif