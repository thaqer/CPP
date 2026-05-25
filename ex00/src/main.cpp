/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:24:31 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/25 18:53:33 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	
	std::string FileName = "data.csv";
	std::map<std::string, double> exchange_rate;
	BitcoinExchange exchange;
	
	if (!exchange.save_data(FileName, exchange_rate))
	{
		std::cerr << "Error: Failed to save data" << std::endl;
		return 1;
	}
	
	if (!exchange.get_data(argv[1], exchange_rate))
	{
		std::cerr << "Error: Failed to get data" << std::endl;
		return 1;
	}
	return 0;
}
