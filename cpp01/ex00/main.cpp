/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:16:25 by skarim            #+#    #+#             */
/*   Updated: 2024/05/10 12:14:27 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z1 = newZombie("zombie111");
	Zombie	z2;
	
	z1->announce();
	delete z1;
	z2.setName("zombie222");
	z2.announce();
	randomChump("zombie333");
	
	return (0);
}