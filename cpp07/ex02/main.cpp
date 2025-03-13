/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:01:29 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 17:47:33 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    unsigned int n = 10;
    Array<int> b;
    Array<int> a(n);
    unsigned int index = 9;
    
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++)
    {
        a[i] = rand() % 19;
    }
    std::cout << "Array a: " << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std:: cout << a[i];
        if (i < a.size() - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

    b = a;
    try{
        b[index] = 13; 
    }
    catch(const std::exception &e)
    {
        std::cout << "the index is out of bounds" << std::endl;
    }
    std::cout << "b[0]: " << b[0] << std::endl;
    std::cout << "Array b: " << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        std:: cout << b[i];
        if (i < b.size() - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    
    return (0);
}