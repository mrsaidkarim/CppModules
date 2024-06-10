/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:17:33 by skarim            #+#    #+#             */
/*   Updated: 2024/06/04 17:30:28 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;
}
		
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called for Dog" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}