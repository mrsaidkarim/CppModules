/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:44:47 by skarim            #+#    #+#             */
/*   Updated: 2024/06/08 11:55:29 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "Copy constructor called for WrongCat" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat" << std::endl;
}
		
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Copy assignment operator called for WrongCat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
