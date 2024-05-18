/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:07:09 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:52:03 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;
	
	h.complain("ERROR");
	h.complain("WARNING");
	h.complain("DEBUG");
	h.complain("INFO");
    return (0);
}