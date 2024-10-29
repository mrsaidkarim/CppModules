/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:42:05 by skarim            #+#    #+#             */
/*   Updated: 2024/10/29 13:56:48 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
class ScalarConverter
{
    private:
        ScalarConverter();
        static bool isInt(const std::string &s);
        static bool isFloatOrDouble(const std::string &s);
        static bool isChar(const std::string &s);
        // static bool isDouble(const std::string &s);
    public:
        static void convert(const std::string &s);
};

#endif