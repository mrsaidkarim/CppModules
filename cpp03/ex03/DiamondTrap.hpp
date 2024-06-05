/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:42:55 by skarim            #+#    #+#             */
/*   Updated: 2024/06/03 16:27:38 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &);
		DiamondTrap(const DiamondTrap &);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &);
		void attack(const std::string& target);
		void whoAmI() const;
};

#endif
