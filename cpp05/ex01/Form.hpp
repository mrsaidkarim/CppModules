/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:19:56 by skarim            #+#    #+#             */
/*   Updated: 2024/10/22 17:46:45 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExec;
    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExec);
        Form(const Form &other);
        ~Form();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        Form &operator=(const Form &other);
        void beSigned(const Bureaucrat &b);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &print, const Form &f);

#endif