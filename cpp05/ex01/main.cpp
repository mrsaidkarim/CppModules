/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:59 by skarim            #+#    #+#             */
/*   Updated: 2024/10/25 10:33:02 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "-------- test1 --------\n";
        Form f1("testform", 3, 5);
        Bureaucrat b1("someone", 1);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "-------- test2 --------\n";
        Form f2("anotherform", 3, 5);
        Bureaucrat b2("anotherbureaucrat", 5);
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}