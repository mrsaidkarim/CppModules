/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:36:32 by skarim            #+#    #+#             */
/*   Updated: 2025/03/15 23:34:15 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){}
        MutantStack(const MutantStack &other)
        {
            *this = other;
        }
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
            {
                std::stack<T>::operator=(other);
            }
            return (*this);
        }
        ~MutantStack(){}
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
        const_iterator cbegin() const
        {
            return (this->c.cbegin());
        }
        const_iterator cend() const
        {
            return (this->c.cend());
        }
        reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }
        reverse_iterator rend()
        {
            return (this->c.rend());
        }
        const_reverse_iterator crbegin() const
        {
            return (this->c.crbegin());
        }
        const_reverse_iterator crend() const
        {
            return (this->c.crend());
        }
};

#endif