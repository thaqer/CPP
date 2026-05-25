/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:11:38 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/25 18:54:28 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {(void)other;}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::save_data(const std::string &file, std::map<std::string, double> &exchange_rates)
{
    std::ifstream infd(file.c_str());
    if (!infd.is_open())
    {
        std::cerr << "Error: Could not open file." << file << std::endl;
        return false;
    }

    std::string line;
    if (std::getline(infd, line))
    {
        if (line != "date,exchange_rate")
            infd.seekg(0);
    }

    while (std::getline(infd, line))
    {
        if (line.empty())
            continue;

        std::string key;
        std::string value;
        std::stringstream s(line);
        char del = ',';

        std::getline(s, key, del);
        std::getline(s, value, del);

        std::stringstream valStream(value);

        double valueD;
        if (!(valStream >> valueD))
        {
            std::cerr << "Error: bad value in CSV -> " << value << std::endl;
            continue;
        }

        exchange_rates.insert(std::make_pair(key, valueD));
    }
    return true;
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

bool    validValue(double value)
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

bool    validDate(const std::string &date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2009)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (month == 2 && leap)
    {
        if (day > 29)
            return false;
    }
    else
    {
        if (day > daysInMonth[month - 1])
            return false;
    }
    return true;
}

bool BitcoinExchange::get_data(const std::string &file, std::map<std::string, double> &exchange_rates)
{
    std::ifstream infd(file.c_str());
    if (!infd.is_open())
    {
        std::cerr << "Error: Could not open file." << file << std::endl;
        return false;
    }

    std::string line;
    std::string head;

    std::getline(infd, line);
    head = trim(line);
    if (head != "date | value")
    {
        std::cerr << "Error: Invalid header in input file -> " << head << std::endl;
        return false;
    }
    
    while (std::getline(infd, line))
    {
        if (line.empty())
            continue;

        std::string key;
        std::string value;
        std::stringstream s(line);
        char del = '|';

        if (!std::getline(s, key, del) || !std::getline(s, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        key = trim(key);
        value = trim(value);

        if (!validDate(key))
        {
            std::cerr << "Error: bad input => " << key << std::endl;
            continue;
        }

        std::stringstream valStream(value);
        char extra;

        double valueD;
        if (!(valStream >> valueD) || (valStream >> extra))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (valueD < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (valueD > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator it = exchange_rates.lower_bound(key);

        if (it == exchange_rates.end() || it->first != key)
        {
            if (it == exchange_rates.begin())
            {
                std::cerr << "Error: bad input => " << key << std::endl;
                continue;
            }
            --it;
        }

        std::cout << key << " => " << valueD << " = "
                  << (valueD * it->second) << std::endl;
    }
    return true;
}
