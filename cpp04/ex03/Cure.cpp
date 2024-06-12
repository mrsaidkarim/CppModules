/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:50:02 by skarim            #+#    #+#             */
/*   Updated: 2024/06/11 16:25:09 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const std::string &type) : AMateria(type)
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *cloneCure = new (std::nothrow)Cure(*this);
	if (cloneCure == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
		exit(1);
	}
	return (cloneCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}