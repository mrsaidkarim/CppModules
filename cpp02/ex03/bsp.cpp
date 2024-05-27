/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:16:05 by skarim            #+#    #+#             */
/*   Updated: 2024/05/26 18:33:18 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	triangleArea(const Point &a, const Point &b, const Point &c)
{
	float area;
	
	area = ((a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY()))).toFloat() / 2;
	return ((area < 0)? -area : area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	abc;
	float	pab;
	float	pbc;
	float	pca;

	abc = triangleArea(a, b, c);
	pab = triangleArea(point, a, b);
	pbc = triangleArea(point, b, c);
	pca = triangleArea(point, c, a);
	return (abc == pab + pbc + pca);
}