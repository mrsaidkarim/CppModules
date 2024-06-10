/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:04:41 by skarim            #+#    #+#             */
/*   Updated: 2024/06/04 17:24:28 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called for Animal" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment operator called for animal" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Animal::setType(const std::string &type)
{
	this->type = type;
}

const std::string& Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound!" << std::endl;
}