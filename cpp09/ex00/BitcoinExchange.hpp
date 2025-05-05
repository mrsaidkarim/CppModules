/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:22:33 by skarim            #+#    #+#             */
/*   Updated: 2025/04/15 16:31:22 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void storeData(std::string fileName);
        void display(std::string fileName);
        void multipliedValue(std::string date, float value);
};