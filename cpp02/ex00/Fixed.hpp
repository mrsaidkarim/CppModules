/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:06:28 by skarim            #+#    #+#             */
/*   Updated: 2024/05/21 12:31:25 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const fp );
};

#endif