/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:28:49 by skarim            #+#    #+#             */
/*   Updated: 2024/10/22 15:30:36 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade Too Low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form has not been signed!");
}

AForm::AForm() : name("default"), isSigned(false), gradeSign(150), gradeExec(150)
{}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw GradeTooHighException();
    else if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
}

AForm::~AForm()
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;    
    }
    return (*this);
}

const std::string &AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeSign() const
{
    return (this->gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->gradeExec);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->gradeSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &print, const AForm &f)
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