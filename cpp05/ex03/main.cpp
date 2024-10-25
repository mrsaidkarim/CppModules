/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:07:33 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 22:36:36 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat highGrade("highGrade", 1);

        Intern anIntern;
        std::cout << "------- Test ShrubberyCreationForm -------\n";
        AForm *shrubberyForm = anIntern.makeForm("ShrubberyCreationForm", "home");
        if (shrubberyForm) {
            highGrade.signForm(*shrubberyForm);
            highGrade.executeForm(*shrubberyForm);
        }
        
        std::cout << "------- Test RobotomyRequestForm -------\n";
        AForm *robotForm = anIntern.makeForm("RobotomyRequestForm", "robot");
        if (robotForm) {
            highGrade.signForm(*robotForm);
            highGrade.executeForm(*robotForm);
        }

        std::cout << "------- Test PresidentialPardonForm -------\n";
        AForm *pardonForm = anIntern.makeForm("PresidentialPardonForm", "john");
        if (pardonForm) {
            highGrade.signForm(*pardonForm);
            highGrade.executeForm(*pardonForm);
        }

        std::cout << "------- Test UnknownForm -------\n";
        AForm *unknownForm = anIntern.makeForm("UnknownForm", "test");
        if (unknownForm) {
            highGrade.signForm(*unknownForm);
            highGrade.executeForm(*unknownForm);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}