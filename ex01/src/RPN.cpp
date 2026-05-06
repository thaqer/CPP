/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:25:12 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/04/25 20:15:01 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) {(void)other}
RPN& RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}
RPN::~RPN(){}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream instream(expression); // for parsing the expression
	std::string token;
	
	bool valid = true;
	
	while (instream >> token)
	{
		valid = true;
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (stack.size() < 2)
			{
				valid = false;
				break;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (token[0] == '+')
				stack.push(a + b);
			else if (token[0] == '-')
				stack.push(a - b);
			else if (token[0] == '*')
				stack.push(a * b);
			else if (token[0] == '/')
				stack.push(a / b);
		}
		else
		{
			try
			{
				int num = std::stoi(token);
				stack.push(num);
			}
			catch (const std::exception&)
			{
				valid = false;
				break;
			}
		}
	}

	if (!valid || stack.size() != 1)
		throw std::invalid_argument("Invalid expression");

	return stack.top();}

}