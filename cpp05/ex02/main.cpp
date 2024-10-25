/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:07:33 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 21:49:39 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat LowGrade("LowGrade", 130);
        Bureaucrat MedGrade("MedGrade", 40);
        Bureaucrat HighGrade("HighGrade", 1);

        ShrubberyCreationForm SCF("home");
        RobotomyRequestForm RRF("robot");
        PresidentialPardonForm PPF("john");
        
        std::cout << "------- Test ShrubberyCreationForm With LowGrade -------\n";
        LowGrade.signForm(SCF);
        LowGrade.executeForm(SCF);

        std::cout << "\n------- Test RobotomyRequestForm With MedGrade -------\n";
        MedGrade.signForm(RRF);
        MedGrade.executeForm(RRF);

        std::cout << "\n------- Test RobotomyRequestForm With HighGrade -------\n";
        HighGrade.signForm(RRF);
        HighGrade.executeForm(RRF);

        std::cout << "\n------- Test PresidentialPardonForm With HighGrade -------\n";
        HighGrade.signForm(PPF);
        HighGrade.executeForm(PPF);

        std::cout << "\n------- Test PresidentialPardonForm With MedGrade -------\n";
        MedGrade.signForm(PPF);
        MedGrade.executeForm(PPF);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}