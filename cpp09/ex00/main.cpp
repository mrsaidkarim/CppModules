/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 16:45:59 by skarim            #+#    #+#             */
/*   Updated: 2025-04-29 16:45:59 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong Parameters! (ex: ./btc input.txt)\n";
    }
    else
    {
        BitcoinExchange bt;
        std::string file(av[1]);
        bt.storeData("data.csv");
        bt.display(file);
    }
}