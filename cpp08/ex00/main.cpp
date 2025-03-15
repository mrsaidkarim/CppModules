/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:26:27 by skarim            #+#    #+#             */
/*   Updated: 2025/03/14 03:09:02 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> vec;
    
    vec.push_back(13);
    vec.push_back(3);
    vec.push_back(7);
    try
    {
        std::vector<int>::iterator itr = easyfind(vec, 15);
        std::cout << "Found " << *itr;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::vector<int>::iterator itr = easyfind(vec, 7);
        std::cout << "Found " << *itr << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(9);
    lst.push_back(4);
    lst.push_back(9);
    try
    {
        std::list<int>::iterator itr = easyfind(lst, 9);
        std::cout << "Found " << *itr << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::list<int>::iterator itr = easyfind(lst, 15);
        std::cout << "Found " << *itr << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
