/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:58:27 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:21:05 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 4;
	Zombie* horde = zombieHorde(N, "test");
	
	if (horde == nullptr)
	{
		std::cout << "Failed to create zombie horde!" << std::endl;
		return (1);
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}