/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:24:07 by skarim            #+#    #+#             */
/*   Updated: 2024/06/11 17:25:35 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

void MateriaSource::clearMaterias()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = nullptr;
		}
	}
}

MateriaSource::~MateriaSource()
{
	clearMaterias();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		clearMaterias();
		for(int i = 0; i < 4; i++)
		{
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = nullptr;
				
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return (materias[i]->clone());
	}
	return (0);
}