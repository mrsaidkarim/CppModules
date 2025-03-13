/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:24:13 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 17:24:53 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T               *_array;
        unsigned int    _size;
    public:
        Array() : _array(NULL), _size(0) {}
        
        Array(unsigned int n) : _size(n)
        {
            _array = new T[n]();
        }
        
        Array &operator=(const Array& other)
        {
            if (this != &other)
            {
                if (_array)
                    delete [] _array;
                _size = other._size;
                this->_array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    this->_array[i] = other._array[i];
            }
            return (*this);
        }
        
        Array(const Array& other) : _array(NULL), _size(0)
        {
            *this = other;
        }
        
        ~Array()
        {
            if (_array)
                delete[] _array;
        }
        
        const T &operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::exception();
            return (_array[index]);
        }
        
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return (_array[index]);
        }

        unsigned int size() const
        {
            return (_size);
        }
};

#endif