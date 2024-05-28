/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:39:04 by skarim            #+#    #+#             */
/*   Updated: 2024/05/28 17:57:47 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    Point point1(5, 5);
    Point point2(15, 5);
    
    std::cout << "Point1 : (" << point1.getX() << "-" << point1.getY() << ")" << std::endl;
    std::cout << "Point1 : (" << point2.getX() << "-" << point2.getY() << ")" << std::endl;


    std::cout << "Point1 is " << (bsp(a, b, c, point1) ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Point2 is " << (bsp(a, b, c, point2) ? "inside" : "outside") << " the triangle." << std::endl;

    return 0;
}