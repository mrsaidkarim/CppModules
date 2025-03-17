/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:36:29 by skarim            #+#    #+#             */
/*   Updated: 2025/03/15 23:38:22 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
void printContainer(T &c)
{
    typename T::iterator begin = c.begin();
    typename T::iterator end = c.end();
    
    while (begin != end)
    {
        std::cout << *begin;
        begin++;
        if (begin != end)
            std::cout << ", ";
    }
    std::cout << "\n";
}

int main()
{
    MutantStack<int> ms1;
    
    ms1.push(13);
    ms1.push(3);
    ms1.push(7);
    ms1.push(4);
    ms1.push(2);
    
    std::cout << "Top of stack: " << ms1.top() << std::endl;
    ms1.pop();
    std::cout << "Top of stack: " << ms1.top() << std::endl;
    std::cout << "Print ms1: ";
    printContainer(ms1);

    MutantStack<int> ms2(ms1);
    std::cout << "Print ms2: ";
    printContainer(ms2);

    MutantStack<int>::reverse_iterator r_begin= ms2.rbegin();
    MutantStack<int>::reverse_iterator r_end= ms2.rend();
    
    while (r_begin != r_end)
    {
        std::cout << *r_begin;
        r_begin++;
        if (r_begin != r_end)
            std::cout << ", ";
    }
    std::cout << "\n";

    std::list<int> lst;
    lst.push_back(13);
    lst.push_back(3);
    lst.push_back(7);
    lst.push_back(4);
    lst.push_back(2);
    std::cout << "Back of list: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Back of list: " << lst.back() << std::endl;
    std::cout << "Print lst: ";
    printContainer(lst);
    return (0);
}