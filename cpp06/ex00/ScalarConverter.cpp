/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:42:07 by skarim            #+#    #+#             */
/*   Updated: 2025/03/11 03:58:26 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void =(a)
{
    this= a
}

void >>(sa_sigaction)
{
    return out
}
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

void    PrintChar(double d)
{
    cout << "char: " << s[0] << endl;
    cout << "int: " << static_cast<int>s << endl;
    cout << "float: " << static_cast<float>s << endl;
    cout << "double: " << static_cast<double>s << endl;
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
            PrintChar(strtod(s.c_str(), tmp));
        else if (type == Float)
            PrintFloat(strtod(s.c_str(), tmp));
        else if (type == Int)
            PrintInt(strtod(s.c_str(), tmp));
        else if (type == Double)
            PrintDouble(strtod(s.c_str(), tmp));
        else
            PrintImpossible();
    }
}