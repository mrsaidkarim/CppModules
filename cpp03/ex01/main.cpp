/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:43:54 by skarim            #+#    #+#             */
/*   Updated: 2024/05/31 18:39:54 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "------ Creating ClapTrap object ------" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("target2");
    clap.takeDamage(20);
    clap.beRepaired(2);

	std::cout << "------ Creating ScavTrap object ------" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("target1");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    scav.attack("target2");
    scav.takeDamage(80);
    scav.beRepaired(10);

    return 0;
}
