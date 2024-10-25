/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:28:49 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 20:19:44 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade Too Low");
}

Form::Form() : name("default"), isSigned(false), gradeSign(150), gradeExec(150)
{}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}


Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
}

Form::~Form()
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;    
    }
    return (*this);
}

const std::string &Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeSign() const
{
    return (this->gradeSign);
}

int Form::getGradeExec() const
{
    return (this->gradeExec);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->gradeSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &print, const Form &f)
{
    print << "Form " << f.getName();
    if (f.getIsSigned())
        print << " is signed ";
    else
        print << " isn't signed ";
    print << ", requires grade " << f.getGradeSign() << " to sign it";
    print << ", requires grade " << f.getGradeExec() << " to execute it";
    return (print);
}