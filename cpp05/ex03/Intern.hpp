/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:15:23 by skarim            #+#    #+#             */
/*   Updated: 2024/10/24 18:33:27 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        AForm *createShrubberyCreationForm(const std::string &target) const;
        AForm *createRobotomyRequestForm(const std::string &target) const;
        AForm *createPresidentialPardonForm(const std::string &target) const;
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();

        Intern &operator=(const Intern &other);
        AForm *makeForm(const std::string &name, const std::string &target);
};

#endif