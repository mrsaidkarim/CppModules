/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 16:45:39 by skarim            #+#    #+#             */
/*   Updated: 2025-04-29 16:45:39 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_database = other._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::storeData(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: couldn't open database file!\n";
    }
    else
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::istringstream ss(line);

            std::string date;
            std::string rate;
            if (std::getline(ss, date, ',') && std::getline(ss, rate))
            {
                _database[date] = std::atof(rate.c_str());
            }
        }
        file.close();
    }
}

void errorInput()
{
    std::cerr << "A quick reminder 😁 for the input file format: date | value\n";
}

int isValidDate(std::string &date)
{
    if (date.empty() || date[date.length() - 1] != ' ')
        return (errorInput(), -1);
    else
        date.erase(date.size() - 1);
    // if (!date.empty())
    // {
    //     if (date[date.length() - 1] != ' ')
    //         return (errorInput(), -1);
    //     date.erase(date.size() - 1);
    // }
    for (int i = 0; i <= 9; i++)
    {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return (0);
        if ((i == 4 || i == 7) && date[i] != '-')
            return (0);
    }
    std::string year, month, day;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    int m,d,y;
    y = atoi(year.c_str());
    m = atoi(month.c_str());
    d = atoi(day.c_str());
    if (m == 0 || m > 12 || d == 0 || d > 31)
        return (0);
    if (m == 2)
    {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            return (d <= 29);
        else
            return (d <= 28);
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);
    return (1);
}

bool isNotNumber(std::string value)
{
    size_t  i = 0;
    int     pointIndex = -1;

    if (value[i] == '-' || value[i] == '+')
        i++;
    while (i < value.size())
    {
        if (!isdigit(value[i]) && (i == value.size() - 1 || !(value[i] == '.' && pointIndex == -1)))
            return (std::cerr << "Error: invalid number format.\n", false);
        if (value[i] == '.')
            pointIndex = i;
        i++;
    }
    if (i != value.size())
        return (std::cerr << "Error: invalid number format.\n", false);
    return (true);
}

bool isValidValue(std::string &value)
{
    if (!value.empty())
    {
        if (value[0] != ' ')
            return (errorInput(), false);
        value.erase(0, 1);
    }
    if (value.empty() || value[0] == '-'|| !isNotNumber(value))
    {
        if (value.empty())
            std::cerr << "Error: empty value.\n" ;
        else if (value[0] == '-')
            std::cerr << "Error: not a positive number.\n";
        return (false);
    }
    float nbr = std::atof(value.c_str());
    if (nbr > 1000)
    {
        std::cerr << "Error: too large a number.\n";
        return (false);
    }
    return (true);
}

void    BitcoinExchange::multipliedValue(std::string date, float value)
{
    std::map<std::string, float>::iterator it = _database.upper_bound(date);

    if (it != _database.begin())
        it--;
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::display(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: couldn't open the input file!\n";
    }
    else
    {
        std::string line;
        std::getline(file, line);
        if (line != "date | value")
            return (errorInput());
        while (std::getline(file, line))
        {
            std::istringstream  ss(line);
            std::string         date;
            std::string         value;

            std::getline(ss, date, '|');
            std::getline(ss, value);
            int tmp = isValidDate(date);
            if (tmp <= 0)
            {
                if (!tmp)
                    std::cerr << "Error: bad input => " << date << " (format: YYYY-MM-DD)" << std::endl;
                continue;
            }
            if (!isValidValue(value))
                continue;
            float v = std::atof(value.c_str());
            multipliedValue(date, v);
        }
    }
}
