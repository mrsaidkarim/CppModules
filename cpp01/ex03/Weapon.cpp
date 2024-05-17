/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:47:40 by skarim            #+#    #+#             */
/*   Updated: 2024/05/13 18:51:27 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	
}

std::string Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

