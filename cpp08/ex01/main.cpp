/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:50:18 by skarim            #+#    #+#             */
/*   Updated: 2025/03/15 03:07:17 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "---------- A valid span: ----------\n";
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << "\n---------- An empty span: ----------\n";
    Span empty(3);
    try{
        int tmp = empty.longestSpan();
        std::cout << "shortest span: " << tmp << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---------- A span with identical elements: ----------\n";
    Span ident(3);
    for (int i = 0; i < 3; i++)
        ident.addNumber(1);
    try{
        int tmp = ident.shortestSpan();
        std::cout << "shortest span: " << tmp << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---------- A large span with 10000 elements: ----------\n";
    Span large(10000);
    for (int i = 0; i < 10000; i++)
        large.addNumber(i);
    std::cout << large.shortestSpan() << std::endl;
    std::cout << large.longestSpan() << std::endl;

    std::cout << "\n---------- A span with  range of iterators ----------\n";
    Span sitr(7);
    sitr.addNumber(88);
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(9);
    lst.push_back(4);
    lst.push_back(12);
    sitr.fillSpan(lst.begin(), lst.end());
    
    sitr.addNumber(77);
    std::cout << sitr.shortestSpan() << std::endl;
    std::cout << sitr.longestSpan() << std::endl;
    try
    {
        sitr.fillSpan(lst.begin(), lst.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}