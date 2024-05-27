/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:07:46 by skarim            #+#    #+#             */
/*   Updated: 2024/05/26 18:03:17 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		Point &operator=(const Point &other);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif