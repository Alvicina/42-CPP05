/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:56:04 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/16 16:49:43 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;	
			
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, const int gradeSign, const int gradeExecute);
		AForm(const AForm &a);
		AForm& operator=(const AForm &a);
		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeSign() const;
		int				getGradeExecute() const;
		void			beSigned(Bureaucrat &a);
		virtual void 	execute(Bureaucrat const &executor) const =0;
		//void			checkForm(Bureaucrat const &executor) const;
		
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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Not signed");
				}
		};
		
};

std::ostream& operator<<(std::ostream &o, const AForm &a);

#endif