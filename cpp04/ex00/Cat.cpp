/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:17:29 by skarim            #+#    #+#             */
/*   Updated: 2024/06/04 17:32:52 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Default constructor called for cat" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor called for cat" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Destructor called for cat" << std::endl;
}
		
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called for cat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}