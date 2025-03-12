/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:42:07 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 03:54:01 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    
}

Types DetectType(const std::string &s)
{
    char    *end;
    double  number;
    
    if (std::isalpha(s[0]) && !s[1])
        return Char;
    number = std::strtod(s.c_str(), &end);
    if (end[0] == 'f' && !end[1] && number <= FLT_MAX && number >= -FLT_MAX)
        return Float;
    else if (!end[0] && number <= INT_MAX && number >= INT_MIN)
        return Int;
    else if (!end[0])
        return Double;
    return Impossible;
}

void    PrintChar(const std::string &s)
{
    std::cout << "char: '" << s[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(s[0])<< std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(s[0])<< std::endl;
}

void PrintFloat(double d)
{
    if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(d)<< std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(d)<< std::endl;
}

void PrintInt(double d)
{
    if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << d << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(d)<< std::endl;
}

void PrintDouble(double d)
{
    if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void PrintImpossible()
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

void ScalarConverter::convert(const std::string &s)
{
    if (s == "nan" || s == "nanf")
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
    else if (s == "+inf" || s == "+inff")
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
    else if (s == "-inf" || s == "-inff")
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
    else
    {
        char *tmp;
        Types type = DetectType(s);
        if (type == Char)
            PrintChar(s);
        else if (type == Float)
            PrintFloat(strtod(s.c_str(), &tmp));
        else if (type == Int)
            PrintInt(strtod(s.c_str(), &tmp));
        else if (type == Double)
            PrintDouble(strtod(s.c_str(), &tmp));
        else
            PrintImpossible();
    }
}