/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:24:17 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 15:54:54 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "defaultName";
}

Zombie::~Zombie()
{
	std::cout << "The zombie " << this->name << " destroyed!" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string& 	Zombie::getName() const
{
	return (this->name);
}

void	Zombie::setName(const std::string& name)
{
	this->name = name;
}