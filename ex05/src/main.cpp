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

#include "harl.hpp"

int main()
{
	Harl *harl = new Harl();
	
	harl->complain("DEBUG");
	harl->complain("INFO");
	harl->complain("WARNING");
	harl->complain("ERROR");

	delete harl;
	return 0;

}