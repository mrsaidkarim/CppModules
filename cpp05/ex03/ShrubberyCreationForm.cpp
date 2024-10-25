/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:43:41 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 15:07:44 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeSign(), other.getGradeExec())
{
    this->target = other.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    
    std::ofstream outfile(this->target + "_shrubbery");
    if (outfile.is_open())
    {
        outfile << "      /\\      \n";
        outfile << "     /  \\     \n";
        outfile << "    /    \\    \n";
        outfile << "   /______\\   \n";
        outfile << "     ||||      \n";
        outfile.close();
    }
    else
        std::cerr << "Error Creating File\n";
}