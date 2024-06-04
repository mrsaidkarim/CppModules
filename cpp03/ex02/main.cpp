/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:51:14 by skarim            #+#    #+#             */
/*   Updated: 2024/06/03 16:09:36 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "------ Creating ClapTrap object ------" << std::endl;
	ClapTrap clap("clappy");
	clap.attack("target1");
	clap.takeDamage(8);
	clap.beRepaired(3);
	clap.takeDamage(16);
	clap.beRepaired(5);

	std::cout << "------ Creating FragTrap object ------" << std::endl;
	FragTrap frag("fragy");
	frag.attack("target1");
	frag.takeDamage(8);
	frag.beRepaired(3);
	frag.takeDamage(16);
	frag.beRepaired(5);
}