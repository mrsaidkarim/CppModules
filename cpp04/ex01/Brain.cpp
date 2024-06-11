/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:36:30 by skarim            #+#    #+#             */
/*   Updated: 2024/06/08 19:58:03 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Copy assignment operator called for Brain" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}