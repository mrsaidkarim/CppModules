/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:20:17 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:39:31 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : w(w)
{
	this->name = name;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->w.getType() << std::endl;
}