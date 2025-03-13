/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:25:04 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 23:40:18 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*ft)(T &))
{
    if (!arr || !ft)
    {
        std::cerr << "Invalid args!\n";
        return ;
    }
    for (int i = 0; i < len; i++)
        ft(arr[i]);
}

template <typename T>
void iter(T *arr, int len, void (*ft)(T const&))
{
    if (!arr || !ft)
    {
        std::cerr << "Invalid args!\n";
        return ;
    }
    for (int i = 0; i < len; i++)
        ft(arr[i]);
}

#endif