/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:50:23 by skarim            #+#    #+#             */
/*   Updated: 2024/06/03 16:15:09 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &str);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &other);
		void attack(const std::string& target);
		void guardGate() const;
};

#endif