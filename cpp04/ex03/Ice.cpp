/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:49:56 by skarim            #+#    #+#             */
/*   Updated: 2024/06/11 16:26:50 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const std::string &type) : AMateria(type)
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice::~Ice()
{
}
		
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria *cloneIce = new (std::nothrow)Ice(*this);
	if (cloneIce == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
		exit(1);
	}
	return (cloneIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}