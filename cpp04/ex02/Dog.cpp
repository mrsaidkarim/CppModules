/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:17:33 by skarim            #+#    #+#             */
/*   Updated: 2024/06/08 18:26:58 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor called for Dog" << std::endl;
	this->type = "Dog";
	this->b = new (std::nothrow) Brain();
	if (!this->b)
	{
		std::cout << "Failed to allocate memory" << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	this->b = NULL;
	*this = other;
}

Dog::~Dog()
{
	delete this->b;
	std::cout << "Destructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called for Dog" << std::endl;
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

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}