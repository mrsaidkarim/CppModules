/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 12:51:31 by skarim            #+#    #+#             */
/*   Updated: 2025-05-05 12:51:31 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_expression = other._expression;
    }
    return (*this);
}

RPN::~RPN()
{
}

void    errorInput(const std::string msg)
{
    std::cerr << "Error: " << msg << std::endl;
}

bool    isOperator(char c)
{
    return (c == '-' || c == '+' || c == '/' || c == '*');
}

bool    RPN::performOperation(char c)
{
    if (this->_expression.size() < 2)
        return (errorInput("insufficient operands for operation."), false);
    int a,b;
    b = this->_expression.top();
    this->_expression.pop();
    a = this->_expression.top();
    this->_expression.pop();
    switch (c)
    {
        case '-':
            this->_expression.push(a - b);
            break;
        case '+':
            this->_expression.push(a + b);
            break;
        case '*':
            this->_expression.push(a * b);
            break;
        case '/':
            if (b != 0)
                this->_expression.push(a / b);
            else
                return (errorInput("division by zero."), false);
            break;
        default:
            break;
    }
    return (true);
}

void    RPN::calculate(const std::string &exp)
{
    for(size_t i = 0; i < exp.length(); i++)
    {
        if (i & 1)
        {
            if (exp[i] != ' ')
                return (errorInput("invalid syntax."));
        }
        else
        {
            if (isOperator(exp[i]))
            {
                if (!performOperation(exp[i]))
                    return ;
            }
            else if (isdigit(exp[i]))
                this->_expression.push(exp[i] - '0');
            else
                return (errorInput("invalid characters."));
        }
    }
    if (this->_expression.size() > 1)
        return (errorInput("invalid syntax."));
    std::cout << this->_expression.top() << std::endl;
}