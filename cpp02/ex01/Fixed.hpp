/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:35:05 by skarim            #+#    #+#             */
/*   Updated: 2024/05/28 15:09:07 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &f);
		~Fixed();
		
		Fixed &operator=(const Fixed &f);
		
		int getRawBits( void ) const;
		void setRawBits( int const fp );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);  

#endif