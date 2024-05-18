/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:04:22 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 17:06:11 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl h;

	if (ac != 2)
	{
		std::cout << "Worng args number!" << std::endl;
		return (1);
	}
	h.complain(av[1]);
    return (0);
}