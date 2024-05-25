/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:09:39 by skarim            #+#    #+#             */
/*   Updated: 2024/05/25 21:10:08 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(const int nbr)
{
	this->fixedPointValue = nbr << this->fractionalBits;
}

Fixed::Fixed(const float nbr)
{
	this->fixedPointValue = roundf(nbr * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		this->fixedPointValue = f.fixedPointValue;
	}
	return (*this);
}

bool Fixed::operator>(const Fixed &f) const
{
	return (this->fixedPointValue > f.fixedPointValue);
}

bool Fixed::operator>=(const Fixed &f) const
{
	return (this->fixedPointValue >= f.fixedPointValue);
}

bool Fixed::operator<(const Fixed &f) const
{
	return (this->fixedPointValue < f.fixedPointValue);
}

bool Fixed::operator<=(const Fixed &f) const
{
	return (this->fixedPointValue <= f.fixedPointValue);
}

bool Fixed::operator==(const Fixed &f) const
{
	return (this->fixedPointValue == f.fixedPointValue);
}

bool Fixed::operator!=(const Fixed &f) const
{
	return (this->fixedPointValue != f.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
	if (f.fixedPointValue == 0)
	{
		std::cout << "Division by zero" << std::endl;
		exit(1);
	}
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixedPointValue++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixedPointValue--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second ? first : second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first < second ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second ? first : second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first > second ? first : second);
}

Fixed::~Fixed()
{
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

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
