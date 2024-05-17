/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:35:12 by skarim            #+#    #+#             */
/*   Updated: 2024/05/13 21:23:36 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon& w)
{
	this->w = &w;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}