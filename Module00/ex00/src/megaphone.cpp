/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-04 14:08:09 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-04 14:08:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string str;
    	if (argc < 2)
    	{
		std::cerr << "Error: No arguments provided." << std::endl;
		return 1;
    	}
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			str += (char)toupper(argv[i][j]);
			j++;
		}
		if (argv[i + 1])
			str += " ";
		i++;
	}
	std::cout << str << std::endl;
	return 0;
}
