/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:27:38 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/09/18 19:10:52 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename;
    std::string s1;
    std::string s2;

    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);
    std::cout << "Enter the string to be replaced (s1): ";
    std::getline(std::cin, s1);
    std::cout << "Enter the replacement string (s2): ";
    std::getline(std::cin, s2);

    if (s1.empty())
    {
        std::cerr << "Error: (s1) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string buffer;
        size_t pos = 0;
        while (pos < line.length())
        {
            if (line.compare(pos, s1.length(), s1) == 0)
            {
                buffer += s2;
                pos += s1.length();
            }
            else
            {
                buffer += line[pos];
                pos++;
            }
        }
        outputFile << buffer << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
