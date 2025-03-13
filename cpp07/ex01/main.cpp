/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:40:22 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 23:43:01 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(T const &element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
    element += 1;    
}

int main()
{
    int intArray[] = {1, 2 , 3};
    
    iter(intArray, sizeof(intArray)/sizeof(intArray[0]), printElement);
    std::cout << std::endl;
    iter(intArray, sizeof(intArray)/sizeof(intArray[0]), incrementElement<int>);
    iter(intArray, sizeof(intArray)/sizeof(intArray[0]), printElement);
    std::cout << std::endl;
    
    char charArray[] = {'a', 'b', 'c'};
    
    iter(charArray, sizeof(charArray)/sizeof(charArray[0]), printElement);
    std::cout << std::endl;
    iter(charArray, sizeof(charArray)/sizeof(charArray[0]), incrementElement<char>);
    iter(charArray, sizeof(charArray)/sizeof(charArray[0]), printElement);
    std::cout << std::endl;
    return (0);
}