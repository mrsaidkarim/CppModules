/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:42:07 by skarim            #+#    #+#             */
/*   Updated: 2024/10/29 14:29:58 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{}

// bool ScalarConverter::isInt(const std::string &s)
// {
//     int i;

//     // if (s.empty())
//     //     return (false);
//     i = 0;
//     if (s[i] == '-' || s[i] == '+')
//         i++;
//     while (i < s.size())
//     {
//         if (!isdigit(s[i]))
//             return (false);
//         i++;
//     }
//     try
//     {
//         int tmp = std::stoi(s);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return (true);
// }

// bool ScalarConverter::isFloatOrDouble(const std::string &s)
// {
//     int i;

//     i = 0;
//     if (s[i] == '-' || s[i] == '+')
//         i++;
//     while (i < s.size())
//     {
//         if (!isdigit(s[i]))
//             break;
//         i++;
//     }
//     if (s[i] != '.')
//         return (false);
//     i++;
//     while (i < s.size())
//     {
//         if (!isdigit(s[i]))
//             return (false);
//         i++;
//     }
//     try
//     {
//         int tmp = std::stof(s);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return (true);
// }

// bool ScalarConverter::isChar(const std::string &s)
// {
//     if (s.length() == 1)
//         if (s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z')
//             return (true);
//     return (false);
// }

// bool ScalarConverter::isDouble(const std::string &s)
// {
    
// }

// void ScalarConverter::convert(const std::string &s)
// {
//     std::istringstream iss(s);
//     double res;
//     int index = 0;

//     if (isChar(s))
//         res = static_cast<double>(s[0]);
//     else if (isInt(s))
//     {
//         res = std::stoi(s);
//     }
//     else if (isFloatOrDouble(s))
//         res = std::
    
// }

void ScalarConverter::convert(const std::string &s)
{
    int     ValInt;
    float   ValFloat;
    double  ValDouble;
    char    ValChar;

    try
    {
        if (s == "nan" || s == "nanf")
            std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
        else if (s == "+inf" || s == "+inff")
            std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
        else if (s == "-inf" || s == "-inff")
            std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
        else
        {
            ValInt = std::stoi(s);
            ValFloat = std::stof(s);
            ValDouble = std::stod(s);
            ValChar = static_cast<char> (ValInt);
            if (std::isprint(ValChar))
                std::cout << "char: " << ValChar << "\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << ValInt << "\n";
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << ValFloat << "f\n";
            std::cout << "double: " << ValDouble << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Conversion fails:" << e.what() << '\n';
    }
}