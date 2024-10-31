/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:46:32 by skarim            #+#    #+#             */
/*   Updated: 2024/10/29 16:19:18 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data originalData = {1, "skarim"};

    uintptr_t tmp = Serializer::serialize(&originalData);
    Data *deserializedData = Serializer::deserialize(tmp);
    if (&originalData == deserializedData)
        std::cout << "Serialization and deserialization successful\n";
    else
        std::cout << "Serialization and deserialization failed\n";
}