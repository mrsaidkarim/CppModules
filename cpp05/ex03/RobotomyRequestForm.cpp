/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:55:09 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 21:48:43 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeSign(), other.getGradeExec()), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

static int robot_success = 0;

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (this->getGradeExec() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << "drilling noises\n";
    if (robot_success++ % 2)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << "robotomy of " << target << " failed\n";
}
