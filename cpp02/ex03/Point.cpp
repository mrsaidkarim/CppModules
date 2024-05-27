/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:04:20 by skarim            #+#    #+#             */
/*   Updated: 2024/05/26 18:04:23 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::Point(const float x, const float y): x(x), y(y){}

Point::Point(const Point &other): x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}