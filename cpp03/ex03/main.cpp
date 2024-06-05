/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 09:19:00 by skarim            #+#    #+#             */
/*   Updated: 2024/06/03 16:14:41 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main()
{
    // std::cout << "Creating ClapTrap object...\n";
    // ClapTrap clap("Clappy");
    // clap.attack("target1");
    // clap.takeDamage(5);
    // clap.beRepaired(3);
    // clap.attack("target2");
    // clap.takeDamage(20);
    // clap.beRepaired(2);

    // std::cout << "\nCreating ScavTrap object...\n";
    // ScavTrap scav("Scavvy");
    // scav.attack("target1");
    // scav.takeDamage(30);
    // scav.beRepaired(20);
    // scav.guardGate();
    // scav.attack("target2");
    // scav.takeDamage(80);
    // scav.beRepaired(10);

    // std::cout << "\nCreating FragTrap object...\n";
    // FragTrap frag("Fraggy");
    // frag.attack("target1");
    // frag.takeDamage(40);
    // frag.beRepaired(30);
    // frag.highFivesGuys();
    // frag.attack("target2");
    // frag.takeDamage(90);
    // frag.beRepaired(20);

    std::cout << "\nCreating DiamondTrap object...\n";
    DiamondTrap diamond("Diamondy");
    diamond.attack("target1");
    diamond.takeDamage(50);
    diamond.beRepaired(40);
    diamond.whoAmI();
    diamond.attack("target2");
    diamond.takeDamage(100);
    diamond.beRepaired(30);

    std::cout << "\nEnd of main function\n";
    return 0;
}
