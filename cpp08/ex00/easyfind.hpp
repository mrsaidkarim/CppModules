/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:26:24 by skarim            #+#    #+#             */
/*   Updated: 2025/03/13 03:37:30 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
    {
        throw std::runtime_error("No occurrence is found!");
    }
    return (it);
}

#endif