/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:35:12 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:42:07 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	this->w = nullptr;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->w = nullptr;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon& w)
{
	this->w = &w;
}

void HumanB::attack() const
{
	if (this->w)
		std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their " << "there's no weapon yet" << std::endl;
		
}