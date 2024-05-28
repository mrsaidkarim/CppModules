/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:35:39 by skarim            #+#    #+#             */
/*   Updated: 2024/05/28 17:13:53 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) : fixedPointValue(f.fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = nbr << this->fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(nbr * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		this->fixedPointValue = f.fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixedPointValue);
}

void Fixed::setRawBits( int const fp )
{
	this->fixedPointValue = fp;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}