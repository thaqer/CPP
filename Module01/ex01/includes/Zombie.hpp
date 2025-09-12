/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 18:28:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-09-11 18:28:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMPIE_HPP
#define ZOMPIE_HPP

#include <iostream>
#include <string>
#include <sstream>


class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce() const;
	void setName(std::string newName);
};

Zombie* zombieHorde( int N, std::string name );


#endif
