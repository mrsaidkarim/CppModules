/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:43:57 by skarim            #+#    #+#             */
/*   Updated: 2024/05/31 15:03:28 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "Parameterized constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack,";
		std::cout << "insufficient hit points or energy points!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}
		
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}