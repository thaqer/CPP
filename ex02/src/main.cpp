/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:08:57 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/21 22:15:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // 17
    mstack.pop(); // removes 17
    std::cout << mstack.size() << std::endl; // 1 (only 5 is left)
	
    mstack.push(3); // 5, 3
    mstack.push(5); // 5, 3, 5
    mstack.push(737); // 5, 3, 5, 737
    mstack.push(0);  // 5, 3, 5, 737, 0
	
    MutantStack<int>::iterator it = mstack.begin(); // points to 5
    MutantStack<int>::iterator ite = mstack.end();  // points past the last element (after 0)

    ++it; // points to 3
    --it;  // points back to 5
	
    while (it != ite) // iterates through the stack from bottom to top
    {
		std::cout << *it << std::endl;
		++it;
    }
    std::stack<int> s(mstack); // creates a standard stack copy of mstack
    return 0;
}
