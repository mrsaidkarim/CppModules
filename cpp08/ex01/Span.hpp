/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:12:29 by skarim            #+#    #+#             */
/*   Updated: 2025/03/15 03:03:48 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <list>

class Span
{
    private:
       unsigned int _N;
       std::vector<int>  _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);
        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        template<typename Iterator>void fillSpan(Iterator begin, Iterator end)
        {
            if (_numbers.size() + std::distance(begin, end) > _N)
                throw std::runtime_error("Span can't hold these elements!\n");
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif