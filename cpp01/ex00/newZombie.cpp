/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:50:24 by skarim            #+#    #+#             */
/*   Updated: 2024/05/10 12:41:33 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *z = new (std::nothrow) Zombie();

	if (z == nullptr)
	{
		std::cout << "Allocation fails!" << std::endl;
		exit(1);
	}
	z->setName(name);
	return (z);
}