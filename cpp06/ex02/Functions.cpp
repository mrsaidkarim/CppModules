/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:58:18 by skarim            #+#    #+#             */
/*   Updated: 2024/11/14 18:16:27 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"


Base *generate(void)
{
    std::srand(time(0));
    int randomValue = rand() % 3;
    if (randomValue == 0)
        return (new A());
    else if (randomValue == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The type of the object pointed to by p: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "The type of the object pointed to by p: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "The type of the object pointed to by p: C\n";
    else
        std::cout << "Unknown type of the object pointed to by p\n";
}

void identify(Base &p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "The type of the object pointed to by p: A\n";
    }
    catch(const std::exception& e)
    {
        try
        {
            (void) dynamic_cast<B&>(p);
            std::cout << "The type of the object pointed to by p: B\n";
        }
        catch(const std::exception& e)
        {
            try
            {
                (void) dynamic_cast<C&>(p);
                std::cout << "The type of the object pointed to by p: C\n";
            }
            catch(const std::exception& e)
            {
                std::cout << "Unknown type of the object pointed to by p\n";
            }
        }
    }
}