/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:43:15 by skarim            #+#    #+#             */
/*   Updated: 2024/06/11 18:40:07 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
}

Character::	Character(const std::string &name) : name(name)
{
}

Character::Character(const Character &other)
{
	*this = other;
}

void Character::clearInventory()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	}
}

Character::~Character()
{
	clearInventory();
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		clearInventory();
		for(int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == nullptr)
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->inventory[idx])
		this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
		inventory[idx]->use(target);
}