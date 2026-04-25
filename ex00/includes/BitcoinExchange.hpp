/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:11:24 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/25 15:29:18 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{

public:
    BitcoinExchange();
    ~BitcoinExchange();

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    bool save_data(const std::string &file, std::map<std::string, double> &exchange_rates);
    bool get_data(const std::string &file, std::map<std::string, double> &exchange_rates);
};




#endif