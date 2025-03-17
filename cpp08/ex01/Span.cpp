/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:12:31 by skarim            #+#    #+#             */
/*   Updated: 2025/03/15 22:13:14 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{}

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span::~Span()
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        unsigned int i;
        for (i = 0; i < _N; i++)
            _numbers[i] = other._numbers[i];
        while (i < other._N)
            _numbers.push_back(other._numbers[i++]);
        _N = other._N;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (_numbers.size() == _N)
        throw std::runtime_error("Span is full!");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Can't find the shortest span!");
    std::vector<int> sorted = _numbers;
    sort(sorted.begin(), sorted.end());
    unsigned int shortest = INT_MAX;
    for (unsigned int i = 0; i < sorted.size() - 1; i++)
    {
        unsigned int tmp = sorted[i + 1] - sorted[i];
        if (tmp < shortest)
            shortest = tmp;
    }
    return (shortest);
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Can't find the shortest span!");
    int max = *max_element(_numbers.begin(), _numbers.end());
    int min = *min_element(_numbers.begin(), _numbers.end());

    return (max - min);
}
