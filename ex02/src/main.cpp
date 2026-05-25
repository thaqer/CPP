/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/05/25 00:00:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe sorter;

		sorter.run(argc, argv);
	}
	catch (const std::exception &e)
	{
		(void)e;
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
