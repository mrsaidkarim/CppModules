/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:17:29 by skarim            #+#    #+#             */
/*   Updated: 2024/06/09 22:20:17 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor called for cat" << std::endl;
	this->type = "Cat";
	this->b = new (std::nothrow) Brain();
	if (!this->b)
	{
		std::cout << "Failed to allocate memory" << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor called for cat" << std::endl;
	this->b = NULL;
	*this = other;
}

Cat::~Cat()
{
	delete this->b;
	std::cout << "Destructor called for cat" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called for cat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->b)
		{
			*this->b = *other.b;
			return (*this);
		}
		this->b = new (std::nothrow) Brain(*other.b);
		if (!this->b)
		{
			std::cout << "Failed to allocate memory" << std::endl;
			exit(1);
		}
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}