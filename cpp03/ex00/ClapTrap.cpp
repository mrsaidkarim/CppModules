/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:14:53 by skarim            #+#    #+#             */
/*   Updated: 2024/06/01 09:33:46 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack,";
		std::cout << "insufficient hit points or energy points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "insufficient hit points or energy points!" << std::endl;
	}
	hitPoints = (hitPoints <= (int)amount) ? 0 : hitPoints - amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot be repaired,";
		std::cout << "insufficient hit points or energy points!" << std::endl;
	}
	else
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired by " << amount << " hit points!" << std::endl;
	}
}