/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:47:40 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:27:10 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	
}

const std::string& Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}

