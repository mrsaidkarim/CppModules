/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:46:55 by skarim            #+#    #+#             */
/*   Updated: 2024/05/10 13:15:05 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie*	zombies = new(std::nothrow) Zombie[N];
	
	if (N <= 0)
		return (nullptr);
	if (zombies == nullptr)
	{
		std::cout << "Allocation fails!" << std::endl;
		return (nullptr);
	}
	for(int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}